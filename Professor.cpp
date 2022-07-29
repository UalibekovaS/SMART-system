#include <fstream>
#include <iostream>
#include <string>
#include "Professor.h"
#include "Tab.h"
using namespace std;

// CONSTRUCTOR TO INITIALIZE ALL MEMBERS TO ZERO
Professor::Professor()
{
    firstName = "";
    lastName = "";
    email = "";
}

// TO ADD NEW PROFESSOR TO THE SYSTEM
// DONE BY ADMINISTRATOR
void Professor::getDetails()
{

    cout << "\n\t\tEnter Professor's first name: ";
    cin >> this->firstName;
    cout << "\n\t\tEnter Professor's last name: ";
    cin >> this->lastName;
    cout << "\n\t\tEnter the email: ";
    cin >> this->email;
    bool checkemail = is_valid(email);
    cout << "\n\t\t";
    if (checkemail)
    {
        cout << email << " is valid\n";
    }
    else
    {
        cout << email << " is not valid. Check it and enter again. \n\n\t\t";
        cout << "Enter the email: ";
        cin >> this->email;
    }
    storeMember();
}

// DELETE PROFESSOR FUNCTION
void Professor::deleteMember(string &eMail)
{
    ifstream fin;
    ofstream fout;
    fin.open("professors.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\t\tFile not found\n";
    else
    {
        fout.open("temp.dat", ios::out | ios::binary);
        fin.read((char *)&firstName, sizeof(string));
        fin.read((char *)&lastName, sizeof(string));
        fin.read((char *)&email, sizeof(string));
        while (!fin.eof())
        {
            if (email != eMail)
            {
                fout.write((char *)&firstName, sizeof(string));
                fout.write((char *)&lastName, sizeof(string));
                fout.write((char *)&email, sizeof(string));
            }
            fin.read((char *)&firstName, sizeof(string));
            fin.read((char *)&lastName, sizeof(string));
            fin.read((char *)&email, sizeof(string));
        }
        fin.close();
        fout.close();
        remove("professors.dat");
        rename("temp.dat", "professors.dat");
        cout << "\n\t\tProfessor has been successfully deleted!\n";
    }
}

// SHOW PROFESSOR'S DATA
void Professor::showMemberData()
{
    cout << this->firstName << " \t\t\t" << this->lastName << "\t\t\t" << email << endl
         << endl;
}

// STORE THE DATA IN THE FILE
void Professor::storeMember()
{
    ofstream fout;
    fout.open("professors.dat", ios::app | ios::binary);
    fout.write((char *)&firstName, sizeof(string));
    fout.write((char *)&lastName, sizeof(string));
    fout.write((char *)&email, sizeof(string));
    fout.close();
}

// DISPLAY PROFESSORS FUNCTION
void Professor::viewMember()
{
    ifstream fin;
    fin.open("professors.dat", ios::in | ios::binary);
    if (!fin)
    {
        cout << "\n\t\tFile not found\n";
    }
    else
    {
        fin.read((char *)&firstName, sizeof(string));
        fin.read((char *)&lastName, sizeof(string));
        fin.read((char *)&email, sizeof(string));
        while (!fin.eof())
        {
            showMemberData();
            fin.read((char *)&firstName, sizeof(string));
            fin.read((char *)&lastName, sizeof(string));
            fin.read((char *)&email, sizeof(string));
        }
        fin.close();
    }
}

// SEARCH PROFESSOR BY EMAIL
void Professor::searchMember(string &eMail)
{
    int counter = 0;
    ifstream fin;
    fin.open("professors.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\nFile not found";
    else
    {
        fin.read((char *)&firstName, sizeof(string));
        fin.read((char *)&lastName, sizeof(string));
        fin.read((char *)&email, sizeof(string));
        while (!fin.eof())
        {
            if (eMail == email)
            {
                showMemberData();
                counter++;
            }
            fin.read((char *)&firstName, sizeof(string));
            fin.read((char *)&lastName, sizeof(string));
            fin.read((char *)&email, sizeof(string));
        }
        if (counter == 0)
            cout << "\t\tProfessor not found\n\n";
        fin.close();
    }
}

// PROFESSOR EMAIL REGISTER
void Professor::professorEmailEnter()
{
    string eMail;
    cout << "\t\t*******  REGISTRATION   *******\n\n";
    cout << "\t\tPlease enter your email : ";
    cin >> eMail;
    professorRegister(eMail);
}

// PROFESSOR LOGIN PAGE
void Professor::professorLoginEnter()
{
    string username, pass;
    cout << "\n\t\t*******  PROFESSOR LOGIN  *******\n"
         << "\n\t\t";
    cout << "Please enter the username and password\n";
    cout << "\n\t\tUsername: ";
    cin >> username;
    cout << "\n\t\tPassword: ";
    cin >> pass;
    usernamepassCheckProf(username, pass);
}

// PROFESSOR AUTHORIZATION PAGE
void Professor::professorAuthorize()
{
    int choice;
    system("clear");
    cout << "\t\t***** PROFESSOR AUTHORIZATION *****\n\n";
    cout << "\t\t>>Please Choose Your Status\n";
    cout << "\n\t\t1.Login into the system\n"
         << "\n\t\t2.Register to the system\n";
    cout << "\n\t\tYour status : ";
    cin >> choice;
    professorAuthorizeChoice(choice);
}

void Professor::professorAuthorizeChoice(int &choice)
{
    switch (choice)
    {
    case 1:
    {
        system("clear");
        professorLoginEnter();
        break;
    }
    break;
    case 2:
    {
        system("clear");
        professorEmailEnter();
        break;
    }
    default:
    {
        cout << "\n\t\tChoose from the options given above: ";
        cin >> choice;
        professorAuthorizeChoice(choice);
        break;
    }
    }
}

// PROFESSOR USERNAME AND PASSWORD CHECK FUNCTION
void Professor::usernamepassCheckProf(string &username, string &pass)
{
    Tab tab;
    ifstream fin;
    int counter = 0;
    fin.open("professorsregister.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\nFile not found";
    else
    {
        fin.read((char *)&email, sizeof(string));
        fin.read((char *)&userName, sizeof(string));
        fin.read((char *)&passWord, sizeof(string));
        while (!fin.eof())
        {
            if ((username == this->userName) && (pass == this->passWord))
            {
                system("clear");
                tab.professorTab();
                counter++;
            }
            fin.read((char *)&email, sizeof(string));
            fin.read((char *)&userName, sizeof(string));
            fin.read((char *)&passWord, sizeof(string));
        }
        if (counter == 0)
        {
            system("clear");
            cout << "\n\t\tUsername or password is not correct. Please check your entered username and password again\n\n";
            professorLoginEnter();
        }
        fin.close();
    }
}

// PROFESSOR REGISTER FUNCTION
void Professor::professorRegister(string &eMail)
{
    Tab tab;
    ifstream fin;
    int counter = 0;
    fin.open("professors.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\n\t\tFile not found\n";
    else
    {
        fin.read((char *)&email, sizeof(string));
        while (!fin.eof())
        {
            if (eMail == this->email)
            {
                int choice;
                cout << "\n\t\tThe professor with email " << eMail << " is found in the system!\n";
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
                    professorLoginEnter();
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
            fin.read((char *)&email, sizeof(string));
        }
        if (counter == 0)
        {
            system("clear");
            cout << "\n\t\tProfessor is not found. Please check your entered email again\n\n";
            professorEmailEnter();
        }
        fin.close();
    }
}

// PROFESSOR REGISTRATION DATA SAVE FUNCTION
void Professor::getRegisterData()
{
    cout << "\n\t\tEnter the username: ";
    cin >> this->userName;
    cout << "\n\t\tEnter the password: ";
    cin >> this->passWord;
    ofstream fout;
    fout.open("professorsregister.dat", ios::app | ios::binary);
    fout.write((char *)&email, sizeof(string));
    fout.write((char *)&userName, sizeof(string));
    fout.write((char *)&passWord, sizeof(string));
    fout.close();
}

// PROFESSOR REMOVE FUNCTION
// DELETE THE PROFESSOR FROM THE SYSTEM FUNCTION
void Professor::deleteAccountProf(string &eMail)
{
    ifstream fin;
    ofstream fout;
    fin.open("professorsregister.dat", ios::in | ios::binary);
    if (!fin)
        cout << "File not found";
    else
    {
        fout.open("temporary.dat", ios::out | ios::binary);
        fin.read((char *)&email, sizeof(int));
        fin.read((char *)&userName, sizeof(string));
        fin.read((char *)&passWord, sizeof(string));
        while (!fin.eof())
        {
            if (this->email != eMail)
            {
                fout.write((char *)&email, sizeof(int));
                fout.write((char *)&userName, sizeof(string));
                fout.write((char *)&passWord, sizeof(string));
            }
            fin.read((char *)&email, sizeof(int));
            fin.read((char *)&userName, sizeof(string));
            fin.read((char *)&passWord, sizeof(string));
        }
        fin.close();
        fout.close();
        remove("professorsregister.dat");
        rename("temporary.dat", "professorsregister.dat");
    }
}

void Professor::Status(int &status)
{
    Tab professortab;
    switch (status)
    {
    case 1:
    {
        system("clear");
        professortab.professorTab();
        break;
    }
    case 2:
    {
        system("clear");
        professortab.main_menu();
        break;
    }
    case 3:
    {
        system("clear");
        cout << "\t\tYou successfully exited from the system!\n\n";
        break;
    }
    case 4:
    case 5:
    
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

// TO CHECK THE VALIDITY OF THE EMAIL;
bool Professor::is_valid(string &email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0]))
    {

        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;

    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;
         i < email.length(); i++)
    {

        // If the character is '@'
        if (email[i] == '@')
        {

            At = i;
        }

        // If character is '.'
        else if (email[i] == '.')
        {

            Dot = i;
        }
    }

    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;

    // If Dot is present before At
    if (At > Dot)
        return 0;

    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}