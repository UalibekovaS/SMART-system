#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Administrator.h"
#include "UniversityMember.h"
#include "Student.h"
#include "Professor.h"
#include "Tab.h"
#include "Course.h"
#include "Mark.h"
using namespace std;

Tab tab;
// MAIN MENU
void Tab::main_menu()
{
    int status;
    cout << "\n\t*******  UNIVERSITY MANAGEMENT SYSTEM  *******\n"
         << "\n\t\t";
    cout << ">>Please Choose Your Status\n";
    cout << "\n\t\t1.Administrator\n\n\t\t"
         << "2.Student\n\n\t\t"
         << "3.Professor\n\n\t\t"
         << "4.Close Application\n\n";
    cout << "\n\t\tYour status : ";
    cin >> status;
    mainTabOperations(status);
}

// MAIN MENU TAB OPERATIONS
void Tab::mainTabOperations(int &status)
{
    Administrator admin;
    Student student;
    Professor professor;
    switch (status)
    {
    case 1:
        admin.administratorLogin();
        break;
    case 2:
        student.studentAuthorize();
        break;
    case 3:
        professor.professorAuthorize();
        break;
    case 4:
        cout << "\n\t\tProgram is finished! \n\n";
        break;
    default:
    {
        cout << "\n\t\tPlease select from the options given above : ";
        cin >> status;
        mainTabOperations(status);
        break;
    }
    }
}
// ADMINISTRATOR TAB OPERATIONS
void Tab::adminTabOperations(int &operation)
{
    Course course;
    int choice;
    Administrator admin;
    switch (operation)
    {
    // Adding new university member case
    case 1:
    {
        system("clear");
        cout << "\n\t\t>>Please choose who do you want to add:\n";
        cout << "\n\t\t1.Student\n\n\t\t"
             << "2.Professor\n\n\t\t";
        cout << "Your choice : ";
        cin >> choice;
        system("clear");
        admin.addNewMember(choice);
        break;
    }
    case 2:
    {
        system("clear");
        cout << "\n\t\t>>Please choose who do you want to delete:\n";
        cout << "\n\t\t1.Student\n\n\t\t"
             << "2.Professor\n\n\t\t";
        cout << "Your choice : ";
        cin >> choice;
        system("clear");
        admin.deleteMember(choice);
        break;
    }
    case 3:
    {
        system("clear");
        cout << "\n\t\t>>Please choose who do you want to display:\n";
        cout << "\n\t\t1.Student\n\n\t\t"
             << "2.Professor\n\n\t\t";
        cout << "Your choice : ";
        cin >> choice;
        system("clear");
        admin.showMember(choice);
        break;
    }
    case 4:
    {
        system("clear");
        cout << "\n\t\t>>Please choose who do you want to find:\n";
        cout << "\n\t\t1.Student\n\n\t\t"
             << "2.Professor\n\n\t\t";
        cout << "Your choice : ";
        cin >> choice;
        system("clear");
        admin.searchMember(choice);
        break;
    }
    case 5:
    {
        cout << "\n\t\t>>Please choose the operation:\n";
        cout << "\n\t\t1.Add a course\n\n\t\t"
             << "2.Delete a course\n\n\t\t";
        cout << "Your choice : ";
        cin >> choice;
        system("clear");
        switch (choice)
        {
        case 1:
        {
            system("clear");
            admin.addCourse();
            break;
        }
        case 2:
        {
            system("clear");
            string courseCode;
            cout << "\t\t******* REMOVE COURSE TAB *******";
            cout << "\n\n\t\tPlease write the code of the course that you want to delete: ";
            cin >> courseCode;
            admin.deleteCourse(courseCode);
            break;
        }
        default:
            break;
            break;
        }
        break;
    }
    case 6:
    {
        system("clear");
        tab.main_menu();
        break;
    }
    case 7:
    {
        system("clear");
        cout << "\t\tYou succesfully exited from the system!\n\n";
        break;
    }
    default:
    {
        cout << "\n\t\tPlease select from the options given above : ";
        cin >> choice;
        adminTabOperations(choice);
        break;
    }
    }
}
// ADMINISTRATOR TAB
void Tab::administratorTab()
{
    int operation, choice;
    cout << "\n\t\t*******  ADMINISTRATOR TAB  *******\n\n"
         << "\n\t\t";
    cout << ">>Please Choose Your Operation\n";
    cout << "\n\t\t1.Add new student/professor\n\n\t\t"
         << "2.Remove the student/professor\n\n\t\t"
         << "3.See all students/professors\n\n\t\t"
         << "4.Search for a student/professor\n\n\t\t"
         << "5.Add/Remove courses\n\n\t\t"
         << "6.Return to the main page\n\n\t\t"
         << "7.Exit from the system\n\n";
    cout << "\n\t\tYour operation : ";
    cin >> operation;
    system("clear");
    Administrator admin;
    Student student;
    adminTabOperations(operation);
}

// STUDENT TAB
void Tab::studentTab()
{
    int operation;
    int id;
    Course course;
    Student student;
    Mark marks;

    cout << "\t\t******* STUDENT TAB *******"
         << "\n\t\t";
    cout << "\n\n\t\t>>Please Choose Your Operation\n";
    cout << "\n\t\t1.Register a course\n\n\t\t"
         << "2.Remove the course\n\n\t\t"
         << "3.See all the courses\n\n\t\t"
         << "4.Search for a course\n\n\t\t"
         << "5.See the marks\n\n"
         << "\t\t6.Back to the main menu\n";
    cout << "\n\t\tYour operation : ";
    cin >> operation;
    switch (operation)
    {
    case 1:
    {
        system("clear");
        cout << "\t\t******* COURSES REGISTRATION TAB *******\n\n";
        cout << "\n|Course Code|\t\t|Course Name|\t\t|Professor's Fist Name|\t\t|Professor's Last Name|\n\n";
        course.viewCourses();
        course.courseCodeEnter();
        break;
    }
    case 2:
    {
        system("clear");
        int id;
        string cCode;
        cout << "\t\t*******  REMOVE A COURSE TAB *******";
        cout << "\n\t\tPlease enter your student ID: ";
        cin >> id;
        cout << "\n|Course Code|\t\t|Student ID|\n\n";
        course.stCourses(id);
        cout << "\n\n\t\tPlease enter the code of the course that you want to delete: ";
        cin >> cCode;
        course.deleteCourse(cCode);
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the student's main menu\n\n";
        cout << "\t\t2.Exit from the student\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        student.Status(status);
        break;
    }
    case 3:
    {
        system("clear");
        cout << "\t\t******* DISPLAY MY COURSES TAB *******\n\n";
        cout << "\n\t\tPlease enter your student ID: ";
        cin >> id;
        cout << "\n|Course Code|\t\t|Student ID|\n\n";
        course.stCourses(id);
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the student's main menu\n\n";
        cout << "\t\t2.Exit from the student\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        student.Status(status);
        break;
    }
    case 4:
    {
        system("clear");
        string cCode;
        cout << "\t\t******* SEARCH COURSE TAB *******\n\n";
        cout << "\n\n\t\tPlease enter the code of the course that you want to display: ";
        cin >> cCode;
        course.findCourse(cCode);
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the student's main menu\n\n";
        cout << "\t\t2.Exit from the student\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        student.Status(status);
        break;
    }
    case 5:
    {
        system("clear");
        int iD;
        cout << "\t\t******* DISPLAY STUDENT'S MARKS TAB *******\n\n\t\t";
        cout << "\n\n\t\t Please enter your ID: ";
        cin >> iD;
        cout << "\n|Mark|\t\t|Course Code|\n\n";
        marks.displayMarksStud(iD);
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the student's main menu\n\n";
        cout << "\t\t2.Exit from the student\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        student.Status(status);
        break;
    }
    case 6:
    {
        system("clear");
        tab.main_menu();
    }

    default:
        break;
    }
}

// PROFESSOR TAB
void Tab::professorTab()
{
    Mark marks;
    string name;
    Course course;
    Professor professor;
    string courseCode;
    int operation;
    cout << "\t\t******* PROFESSOR TAB *******"
         << "\n\t\t";
    cout << "\n\n\t\t>>Please Choose Your Operation\n";
    cout << "\n\t\t1.See my courses\n\n\t\t"
         << "2.Add Marks\n\n\t\t"
         << "3.Display marks\n\n\t\t"
         << "4.Comeback to the main page\n\n\t\t"
         << "5.Exit from the system\n\n";
    cout << "\n\t\tYour operation : ";
    cin >> operation;
    switch (operation)
    {
    case 1:
    {
        system("clear");
        cout << "\t\t******* DISPLAY COURSES TAB *******";
        cout << "\n\n\t\tPlease Enter your name: ";
        cin >> name;
        cout << "\n|Course code|\t\t|Course Name|\t\t|First Name|\t\t|Last Name|\n\n";
        course.displayCourses(name);
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the professor's main menu\n\n";
        cout << "\t\t2.Exit from the professor\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        professor.Status(status);
        break;
    }
    case 2:
    {
        system("clear");
        cout << "\t\t******* ADD MARKS TAB *******\n\n";
        marks.getMarkDetails();
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the professor's main menu\n\n";
        cout << "\t\t2.Exit from the professor\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        professor.Status(status);
        break;
    }
    case 3:
    {
        system("clear");
        cout << "\t\t******* DISPLAY MARKS TAB *******\n\n\t\t";
        cout << "Please enter the course code: ";
        cin >> courseCode;
        cout << "\n";
        cout << "\n|Student ID|\t\t|Mark|\t\t|Course Code|\n\n";
        marks.showMarksProf(courseCode);
        cout << "\n\t\t>>Please Choose Your Status\n\n";
        cout << "\t\t1.Go back to the professor's main menu\n\n";
        cout << "\t\t2.Exit from the professor\n\n";
        cout << "\t\t3.Exit from the system\n\n";
        cout << "\t\tYour status : ";
        int status;
        cin >> status;
        professor.Status(status);
        break;
    }
    case 4:
    {
        system("clear");
        tab.main_menu();
        break;
    }
    case 5:
    {
        system("clear");
        cout << "\t\tYou succesfully exited from the system!\n\n";
        break;
    }
    default:
    {
        break;
    }
    }
}