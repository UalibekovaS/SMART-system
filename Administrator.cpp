#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Administrator.h"
#include "Student.h"
#include "Professor.h"
#include "UniversityMember.h"
#include "Tab.h"
#include "Course.h"
using namespace std;

Tab admintab;

// CONSTRUCTOR FOR INITIALIZING MEMBERS TO ZERO

Administrator::Administrator()
{
    username = "";
    password = "";
}

// GETTING USERNAME AND PASSWORD FOR LOGIN
void Administrator::getDetails()
{
    cout << "Please enter the username and password\n";
    cout << "\n\t\tUsername: ";
    cin >> userName;
    cout << "\n\t\tPassword: ";
    cin >> passWord;
}

void Administrator::storeMember()
{
}

// STATUS FUNCTION
void Administrator::adminStatus(int &status)
{
    switch (status)
    {
    case 1:
    {
        system("clear");
        admintab.administratorTab();
        break;
    }
    case 2:
    {
        system("clear");
        admintab.main_menu();
        break;
    }
    case 3:
    {
        system("clear");

        break;
    }
    default:
    {
        system("clear");
        cout << "\t\tPlease choose from the options given above : ";
        cin >> status;
        adminStatus(status);
        break;
    }
    }
}

// ADD MEMBER FUNCTION FOR ADMINISTRATOR
void Administrator::addNewMember(int &choice)
{
    UniversityMember *member;
    Student student;
    Professor professor;
    switch (choice)
    {

    // For adding a new student
    case 1:
    {
        member = &student;
        cout << "\n\t\t*******  ADD STUDENT TAB  *******\n\n";
        member->getDetails();
        cout << "\n\n\t\tNew student has been added successfully! \n";
        cout << "\t\t\n\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the administrator's main menu\n\n";
        cout << "\t\t2.Exit from the administrator\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        adminStatus(status);
        break;
    }

    // For adding a new professor
    case 2:
    {
        member = &professor;
        cout << "\n\t\t*******  ADD PROFESSOR TAB  *******\n\n";
        member->getDetails();
        cout << "\n\n\t\tNew Professor has been added successfully! \n";
        cout << "\t\t\n\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the administrator's main menu\n\n";
        cout << "\t\t2.Exit from the administrator\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        adminStatus(status);
        break;
    }
    default:
    {
        cout << "\t\tPlease write only 1 or 2\n\n";
        cout << "\t\tEnter your choice again : ";
        cin >> choice;
        system("clear");
        addNewMember(choice);
        break;
    }
    }
}

// SHOW MEMBER FUNCTION FOR ADMINISTRATOR
void Administrator::showMember(int &choice)
{
    UniversityMember *member1;
    Student student1;
    Professor professor1;
    switch (choice)
    {
    // for showing students list
    case 1:
    {
        member1 = &student1;
        cout << "\n\t\t*******  STUDENTS LIST   *******\n\n";
        cout << "|Student ID|\t\t|First name|\t\t|Last name|\n\n";
        student1.viewMember();
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the administrator's main menu\n\n";
        cout << "\t\t2.Exit from the administrator\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        adminStatus(status);

        break;
    }

    // for showing professors list
    case 2:
    {
        member1 = &professor1;
        cout << "\n\t\t*******  PROFESSOR LIST   *******\n\n";
        cout << "|First name|\t\t|Last name|\t\t|Email|\n\n";
        professor1.viewMember();
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the administrator's main menu\n\n";
        cout << "\t\t2.Exit from the administrator\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        adminStatus(status);

        break;
    }
    default:
    {
        cout << "\t\tPlease write only 1 or 2\n\n";
        cout << "\t\tEnter your choice again : ";
        cin >> choice;
        system("clear");
        showMember(choice);
        break;
    }
    }
}

// ADMINISTRATOR LOGIN FUNCTION
void Administrator::administratorLogin()
{
    string id;
    string pass;
    int count = 0;
    system("clear");
    cout << "\n\t\t*******  ADMINISTRATOR LOGIN  *******\n"
         << "\n\t\t";
    getDetails();
    ifstream input("Administrators.txt"); // check if the username and password exists inside the file Users.txt

    while (input >> id >> pass)
    {
        if ((id == userName) && (pass == passWord))
        {
            count = 1;
            system("clear");
        }
    }
    input.close();

    if (count == 1)
    {
        admintab.administratorTab();
    }
    else
    {
        cout << "\n\t\tLOGIN ERROR! Please check your data\n\n";
        int status;
        cout << "\n\t\t>>Please Choose Your Status\n";
        cout << "\n\t\t1.Try to login again as administrator\n\n\t\t"
             << "2.Return to main menu\n\n\t\t"
             << "3.Close Application\n\n";
        cout << "\n\t\tYour status : ";
        cin >> status;
        switch (status)
        {
        case 1:
            system("clear");
            administratorLogin();
            break;
        case 2:
            system("clear");
            admintab.main_menu();
            break;
        case 3:
            cout << "\n\t\tYou exited succesfully from the program \n\n";
            break;
        default:
            cout << "\n\t\tPlease select from the options given above \n\n";
        }
    }
}

// DELETE MEMBER FUNCTION FOR ADMINISTRATOR
void Administrator::deleteMember(int &choice)
{
    Student student;
    Professor professor;
    switch (choice)
    {
        // For deleting a student
    case 1:
    {
        int studentID;
        cout << "\n\t\t*******  DELETE STUDENT TAB   *******\n\n";
        cout << "\t\tPlease write the student ID of the student that you want to delete : ";
        cin >> studentID;
        student.deleteMember(studentID);
        student.deleteAccount(studentID);
        cout << "\t\t\n\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the administrator's main menu\n\n";
        cout << "\t\t2.Exit from the administrator\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        adminStatus(status);
        break;
    }

        // For deleting a professor
    case 2:
    {
        string email;
        cout << "\n\t\t*******  DELETE PROFESSOR TAB   *******\n\n";
        cout << "\t\tPlease write the email of the professor that you want to delete : ";
        cin >> email;
        professor.deleteMember(email);
        professor.deleteAccountProf(email);
        cout << "\t\t\n\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the administrator's main menu\n\n";
        cout << "\t\t2.Exit from the administrator\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        adminStatus(status);
        break;
    }
    default:
    {
        cout << "\t\tPlease write only 1 or 2\n\n";
        cout << "\t\tEnter your choice again : ";
        cin >> choice;
        system("clear");
        deleteMember(choice);
        break;
    }
    }
}

void Administrator::searchMember(int &choice)
{
    Student student;
    Professor professor;
    switch (choice)
    {
        // For searching a student
    case 1:
    {
        int studentID;
        cout << "\n\t\t*******  SEARCH STUDENT TAB   *******\n\n";
        cout << "\t\tPlease write the student ID of the student that you want to find : ";
        cin >> studentID;
        cout << "\n|Student ID|\t\t|First name|\t\t|Last name|\n\n";
        student.searchMember(studentID);
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the administrator's main menu\n\n";
        cout << "\t\t2.Exit from the administrator\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        adminStatus(status);
        break;
    }

        // For searching a professor
    case 2:
    {
        string email;
        cout << "\n\t\t*******  SEARCH PROFESSOR TAB   *******\n\n";
        cout << "\t\tPlease write the email of the professor that you want to find : ";
        cin >> email;
        cout << "\n|First name|\t\t|Last name|\t\t|Email|\n\n";
        professor.searchMember(email);
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the administrator's main menu\n\n";
        cout << "\t\t2.Exit from the administrator\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        adminStatus(status);
        break;
    }
    default:
    {
        cout << "\t\tPlease write only 1 or 2\n\n";
        cout << "\t\tEnter your choice again : ";
        cin >> choice;
        system("clear");
        searchMember(choice);
        break;
    }
    }
}

// ADD COURSE FUNCTION ADMINISTRATOR
void Administrator::addCourse()
{
    Course course;
    cout << "\t\t******* ADD COURSE TAB *******";
    course.getCourseDetails();
    cout << "\t\t\n\n\t\t>>Please Choose Your Status\n\n";
    cout << "\t\t1.Go back to the administrator's main menu\n\n";
    cout << "\t\t2.Exit from the administrator\n\n";
    cout << "\t\t3.Exit from the system\n\n";
    cout << "\t\tYour status : ";
    int status;
    cin >> status;
    system("clear");
    adminStatus(status);
}

// DELETE COURSE FUNCTION ADMINISTRATOR
void Administrator::deleteCourse(const string &courseCode)
{
    string coursecode;
    Course course;
    cout << "\t\t******* DELETE COURSE TAB *******";
    cout << "Please enter the Course code of the course that you want to delete: ";
    cin >> coursecode;
    course.removeCourse(coursecode);
    cout << "\t\t\n\n\t\t>>Please Choose Your Status\n\n";
    cout << "\t\t1.Go back to the administrator's main menu\n\n";
    cout << "\t\t2.Exit from the administrator\n\n";
    cout << "\t\t3.Exit from the system\n\n";
    cout << "\t\tYour status : ";
    int status;
    cin >> status;
    system("clear");
    adminStatus(status);
}