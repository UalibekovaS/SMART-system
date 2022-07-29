#include <fstream>
#include <iostream>
#include <string>
#include "Student.h"
#include "Tab.h"
#include"Course.h"
using namespace std;

// CONSTRUCTOR TO INITIALIZE ALL THE VARIABLES TO ZERO
Student::Student()
{
    lastName = "";
    studentId = 0;
}

// GET DETAILS OF THE STUDENT FUNCTION
void Student::getDetails()
{
    cout << "\n\t\tEnter Student name: ";
    cin >> this->firstName;
    cout << "\n\t\tEnter Student last name: ";
    cin >> this->lastName;
    cout << "\n\t\tEnter Student ID: ";
    cin >> this->studentId;
    storeMember();
}

// DELETE THE STUDENT FROM THE SYSTEM FUNCTION
void Student::deleteMember(int &studentID)
{
    ifstream fin;
    ofstream fout;
    fin.open("students.dat", ios::in | ios::binary);
    if (!fin)
        cout << "File not found";
    else
    {
        fout.open("temp.dat", ios::out | ios::binary);
        fin.read((char *)&firstName, sizeof(string));
        fin.read((char *)&lastName, sizeof(string));
        fin.read((char *)&studentId, sizeof(int));
        while (!fin.eof())
        {
            if (studentId != studentID)
            {
                fout.write((char *)&firstName, sizeof(string));
                fout.write((char *)&lastName, sizeof(string));
                fout.write((char *)&studentId, sizeof(int));
            }

            fin.read((char *)&firstName, sizeof(string));
            fin.read((char *)&lastName, sizeof(string));
            fin.read((char *)&studentId, sizeof(int));
        }
        fin.close();
        fout.close();
        remove("students.dat");
        rename("temp.dat", "students.dat");
        cout << "\n\t\tStudent has been successfully deleted!\n";
    }
}

// SHOW THE STUDENT DATA FUNCTION
void Student::showMemberData()
{
    cout << this->studentId << " \t\t" << this->firstName << "\t\t\t" << this->lastName << endl
         << endl;
}

// SAVE THE STUDENT DATA IN STUDENTS.DAT FILE FUNCTION
void Student::storeMember()
{
    ofstream fout;
    fout.open("students.dat", ios::app | ios::binary);
    fout.write((char *)&firstName, sizeof(string));
    fout.write((char *)&lastName, sizeof(string));
    fout.write((char *)&studentId, sizeof(int));
    fout.close();
}

// SHOW ALL THE STUDENTS IN THE SYSTEM FUNCTION
void Student::viewMember()
{
    ifstream fin;
    fin.open("students.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "\n\n\t\tFile not found";
    }
    else
    {
        fin.read((char *)&firstName, sizeof(string));
        fin.read((char *)&lastName, sizeof(string));
        fin.read((char *)&studentId, sizeof(int));
        while (!fin.eof())
        {
            showMemberData();
            fin.read((char *)&firstName, sizeof(string));
            fin.read((char *)&lastName, sizeof(string));
            fin.read((char *)&studentId, sizeof(int));
        }
        fin.close();
    }
}

// SEARCH THE STUDENT BY STUDENT ID FUNCTION
void Student::searchMember(int &studentID)
{
    int counter = 0;
    ifstream fin;
    fin.open("students.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\nFile not found";
    else
    {
        fin.read((char *)&firstName, sizeof(string));
        fin.read((char *)&lastName, sizeof(string));
        fin.read((char *)&studentId, sizeof(int));
        while (!fin.eof())
        {
            if (studentID == studentId)
            {
                showMemberData();
                counter++;
            }
            fin.read((char *)&firstName, sizeof(string));
            fin.read((char *)&lastName, sizeof(string));
            fin.read((char *)&studentId, sizeof(int));
        }
        if (counter == 0)
            cout << "\t\tStudent not found\n\n";
        fin.close();
    }
}

// STUDENT ID REGISTER
void Student::studentIDEnter()
{
    int studentID;
    cout << "\t\t*******  REGISTRATION   *******\n\n";
    cout << "\t\tPlease enter your student ID : ";
    cin >> studentID;
    studentRegister(studentID);
}

// STUDENT LOGIN PAGE
void Student::studentLoginEnter()
{
    string username, pass;
    cout << "\n\t\t*******  STUDENT LOGIN  *******\n"
         << "\n\t\t";
    cout << "Please enter the username and password\n";
    cout << "\n\t\tUsername: ";
    cin >> username;
    cout << "\n\t\tPassword: ";
    cin >> pass;
    usernamepassCheck(username, pass);
}

// STUDENT AUTHORIZATION PAGE
void Student::studentAuthorize()
{
    int choice;
    system("clear");
    cout << "\t\t***** STUDENT AUTHORIZATION *****\n\n";
    cout << "\t\t>>Please Choose Your Status\n";
    cout << "\n\t\t1.Login into the system\n"
         << "\n\t\t2.Register to the system\n";
    cout << "\n\t\tYour status : ";
    cin >> choice;
    studentAuthorizeChoice(choice);
}

void Student::studentAuthorizeChoice(int &choice)
{
    switch (choice)
    {
    case 1:
    {
        system("clear");
        studentLoginEnter();
    }
    break;
    case 2:
    {
        system("clear");
        studentIDEnter();
        break;
    }
    default:
    {
        cout << "\n\t\tChoose from the options given above: ";
        cin >> choice;
        studentAuthorizeChoice(choice);
        break;
    }
    }
}

// STUDENT USERNAME AND PASSWORD CHECK FUNCTION
void Student::usernamepassCheck(string &username, string &pass)
{
    Tab tab;
    ifstream fin;
    int counter = 0;
    fin.open("studentsregister.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\nFile not found";
    else
    {
        fin.read((char *)&studentId, sizeof(int));
        fin.read((char *)&userName, sizeof(string));
        fin.read((char *)&passWord, sizeof(string));
        while (!fin.eof())
        {
            if ((username == this->userName) && (pass == this->passWord))
            {
                system("clear");
                tab.studentTab();
                counter++;
            }
            fin.read((char *)&studentId, sizeof(int));
            fin.read((char *)&userName, sizeof(string));
            fin.read((char *)&passWord, sizeof(string));
        }
        if (counter == 0)
        {
            system("clear");
            cout << "\n\t\tUsername or password is not correct. Please check your entered username and password again\n\n";
            studentLoginEnter();
        }
        fin.close();
    }
}

// STUDENT REGISTER FUNCTION
void Student::studentRegister(int &studentID)
{
    Tab tab;
    ifstream fin;
    int counter = 0;
    fin.open("students.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\n\t\tFile not found\n";
    else
    {
        fin.read((char *)&studentId, sizeof(int));
        while (!fin.eof())
        {
            if (studentID == this->studentId)
            {
                int choice;
                cout << "\n\t\tThe student with studentID " << studentID << " is found in the system!\n";
                cout << "\n\n\t\t>>To register please enter your username and password\n";
                getRegisterData();
                cout << "\n\t\tYou were successfully registered in the system!\n\n";
                cout << "\n\t\t>>Please choose your status\n";
                cout << "\n\t\t1.Login into the system\n";
                cout << "\n\t\t2.Comeback to the main page\n";
                cout << "\n\t\t3.Exit from the system";
                cout << "\n\n\t\tYour status : ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    system("clear");
                    studentLoginEnter();
                    break;
                }
                case 2:
                {
                    system("clear");
                    tab.main_menu();
                    break;
                }
                case 3:
                {
                    system("clear");
                    cout << "You exited from the system";
                    break;
                }
                default:
                    break;
                }
                counter++;
            }
            fin.read((char *)&studentId, sizeof(int));
        }
        if (counter == 0)
        {
            system("clear");
            cout << "\n\t\tStudent is not found. Please check your entered studentID again\n\n";
            studentIDEnter();
        }
        fin.close();
    }
}

// STUDENT REGISTRATION DATA SAVE FUNCTION
void Student::getRegisterData()
{
    cout << "\n\t\tEnter the username: ";
    cin >> this->userName;
    cout << "\n\t\tEnter the password: ";
    cin >> this->passWord;
    storeRegisterData();
}

// STUDENT SAVE DATA FUNCTION
int Student::storeRegisterData()
{
    ofstream fout;
    fout.open("studentsregister.dat", ios::app | ios::binary);
    fout.write((char *)&studentId, sizeof(int));
    fout.write((char *)&userName, sizeof(string));
    fout.write((char *)&passWord, sizeof(string));
    fout.close();
    return (1);
}

// STUDENT REMOVE FUNCTION
// DELETE THE STUDENT FROM THE SYSTEM FUNCTION
void Student::deleteAccount(int &studentID)
{
    ifstream fin;
    ofstream fout;
    fin.open("studentsregister.dat", ios::in | ios::binary);
    if (!fin)
        cout << "File not found";
    else
    {
        fout.open("temporary.dat", ios::out | ios::binary);
        fin.read((char *)&studentId, sizeof(int));
        fin.read((char *)&userName, sizeof(string));
        fin.read((char *)&passWord, sizeof(string));
        while (!fin.eof())
        {
            if (this->studentId != studentID)
            {
                fout.write((char *)&studentId, sizeof(int));
                fout.write((char *)&userName, sizeof(string));
                fout.write((char *)&passWord, sizeof(string));
            }
            fin.read((char *)&studentId, sizeof(int));
            fin.read((char *)&userName, sizeof(string));
            fin.read((char *)&passWord, sizeof(string));
        }
        fin.close();
        fout.close();
        remove("studentsregister.dat");
        rename("temporary.dat", "studentsregister.dat");
    }
}

void Student::Status(int &status)
{
    Tab studenttab;
    switch (status)
    {
    case 1:
    {
        system("clear");
        studenttab.studentTab();
        break;
    }
    case 2:
    {
        system("clear");
        studenttab.main_menu();
        break;
    }
    case 3:
    {
        system("clear");
        cout << "\n\t\tYou successfully exited from the system!\n\n";
        break;
    }
    default:
    {
        system("clear");
        cout << "\t\tPlease choose from the options given above : ";
        cin >> status;
        Status(status);
        break;
    }
    }
}

