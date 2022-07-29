#include <iostream>
#include "Course.h"
#include "Professor.h"
#include "Tab.h"
#include "Student.h"
#include <fstream>
#include <string>
using namespace std;

void Course::getCourseDetails()
{
    ofstream fout;
    fout.open("courses.dat", ios::app | ios::binary);
    cout << "\n\n\t\tThe name of the course: ";
    cin >> nameOfTheCourse;
    cout << "\n\t\tThe course code of the course: ";
    cin >> courseCode;
    cout << "\n\t\tEnter the first name of the professor: ";
    cin >> profname;
    cout << "\n\t\tEnter the last name of the professor: ";
    cin >> proflastname;
    fout.write((char *)&nameOfTheCourse, sizeof(string));
    fout.write((char *)&courseCode, sizeof(string));
    fout.write((char *)&profname, sizeof(string));
    fout.write((char *)&proflastname, sizeof(string));
    fout.close();
    cout << "\n\n\t\tCourse(s) has/have been added successfully!\n";
}

void Course::removeCourse(string &CourseCode)
{
    ifstream fin;
    ofstream fout;
    fin.open("courses.dat", ios::in | ios::binary);
    if (!fin)
        cout << "File not found";
    else
    {
        fout.open("temp.dat", ios::out | ios::binary);
        fin.read((char *)&nameOfTheCourse, sizeof(string));
        fin.read((char *)&courseCode, sizeof(string));
        fin.read((char *)&profname, sizeof(string));
        fin.read((char *)&proflastname, sizeof(string));
        while (!fin.eof())
        {
            if (CourseCode != courseCode)
            {
                fout.write((char *)&nameOfTheCourse, sizeof(string));
                fout.write((char *)&courseCode, sizeof(string));
                fout.write((char *)&profname, sizeof(string));
                fout.write((char *)&proflastname, sizeof(string));
            }

            fin.read((char *)&nameOfTheCourse, sizeof(string));
            fin.read((char *)&courseCode, sizeof(string));
            fin.read((char *)&profname, sizeof(string));
            fin.read((char *)&proflastname, sizeof(string));
        }
        fin.close();
        fout.close();
        remove("courses.dat");
        rename("temp.dat", "courses.dat");
        cout << "\n\t\tCourse has been successfully deleted!\n";
    }
}

void Course::displayCourses(string &name)
{
    int counter = 0;
    ifstream fin;
    fin.open("courses.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\nFile not found";
    else
    {
        fin.read((char *)&nameOfTheCourse, sizeof(string));
        fin.read((char *)&courseCode, sizeof(string));
        fin.read((char *)&profname, sizeof(string));
        fin.read((char *)&proflastname, sizeof(string));
        while (!fin.eof())
        {
            if (name == profname)
            {
                showCourseData();
                counter++;
            }
            fin.read((char *)&nameOfTheCourse, sizeof(string));
            fin.read((char *)&courseCode, sizeof(string));
            fin.read((char *)&profname, sizeof(string));
            fin.read((char *)&proflastname, sizeof(string));
        }
        if (counter == 0)
            cout << "\t\tProfessor not found\n\n";
        fin.close();
    }
}

void Course::showCourseData()
{
    cout << "\n"
         << this->courseCode << "\t\t\t" << this->nameOfTheCourse << "\t\t\t\t" << this->profname << "\t\t\t" << this->proflastname << endl;
}
// SHOW ALL COURSES IN THE SYSTEM FUNCTION
void Course::viewCourses()
{
    ifstream cor;
    cor.open("courses.dat", ios::in | ios::binary);
    if (!cor)
    {
        cout << "\n\n\t\tFile not found";
    }
    else
    {
        cor.read((char *)&nameOfTheCourse, sizeof(string));
        cor.read((char *)&courseCode, sizeof(string));
        cor.read((char *)&profname, sizeof(string));
        cor.read((char *)&proflastname, sizeof(string));
        while (!cor.eof())
        {
            showCourseData();
            cor.read((char *)&nameOfTheCourse, sizeof(string));
            cor.read((char *)&courseCode, sizeof(string));
            cor.read((char *)&profname, sizeof(string));
            cor.read((char *)&proflastname, sizeof(string));
        }
        cor.close();
    }
}
void Course::courseCodeEnter()
{
    string Ccode;
    cout << "\n\t\tPlease enter the code of the course\n";
    cout << "\n\t\tCourse code: ";
    cin >> Ccode;
    regCourse(Ccode);
}

// REGISTRATION FOR THE COURSE BY A STUDENT
void Course::regCourse(string &cCode)
{
    Tab tab;
    ifstream tin;
    int counter = 0;
    tin.open("courses.dat", ios::in | ios::binary);
    if (!tin)
        cout << "\n\t\tFile not found\n";
    else
    {
        tin.read((char *)&courseCode, sizeof(string));
        while (!tin.eof())
        {
            if (cCode == this->courseCode)
            {
                int choice;
                cout << "\n\t\tThe course with code " << cCode << " is found in the system!\n";
                cout << "\n\n\t\t>>To register please enter your id \n";
                getRegDataStudCourse();
                cout << "\n\t\tYou was successfully registered to the course!\n\n";
                cout << "\n\t\t>>Please Choose Your Status\n\n";
                cout << "\t\t1.Go back to the student's main menu\n\n";
                cout << "\t\t2.Exit from the student\n\n";
                cout << "\t\t3.Exit from the system\n\n";
                cout << "\t\tYour status : ";

                cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    system("clear");
                    tab.studentTab();
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
                    cout << "\n\t\tYou successfully exited from the system!\n\n";
                    break;
                }
                default:
                    break;
                }
                counter++;
            }
            tin.read((char *)&courseCode, sizeof(string));
        }
        if (counter == 0)
        {
            system("clear");
            cout << "\n\t\tCourse is not found. Please check your entered course code again\n\n";
            courseCodeEnter();
        }
        tin.close();
    }
}
// STUDENT COURSE REGISTRATION DATA SAVE FUNCTION
void Course::getRegDataStudCourse()
{
    /*cout << "\n\t\tEnter course code: ";
    cin >> this->courseCode;*/
    cout << "\n\t\tEnter student ID: ";
    cin >> this->id;
    storeRegDataStudCourse();
}
// STUDENT'S COURSE SAVE DATA FUNCTION
void Course::storeRegDataStudCourse()
{
    ofstream fout;
    fout.open("coursesreg.dat", ios::app | ios::binary);
    fout.write((char *)&id, sizeof(int));
    fout.write((char *)&courseCode, sizeof(string));
    fout.close();
}

// DISPLAY COURSES OF A STUDENT
void Course::stCourses(int &iD)
{
    int counter = 0;
    ifstream tin;
    tin.open("coursesreg.dat", ios::in | ios::binary);
    if (!tin)
        cout << "\nFile not found";
    else
    {
        tin.read((char *)&id, sizeof(int));
        tin.read((char *)&courseCode, sizeof(string));
        while (!tin.eof())
        {
            if (id == iD)
            {
                cout << "\n"
                     << this->courseCode << "\t\t\t" << this->id << "\n\n"
                     << endl;
                counter++;
            }
            tin.read((char *)&id, sizeof(int));
            tin.read((char *)&courseCode, sizeof(string));
        }
        if (counter == 0)
            cout << "\t\t Course is not found\n\n";
        tin.close();
    }
}
// DELETE THE COURSE FROM THE SYSTEM FUNCTION
void Course::deleteCourse(string &Ccode)
{
    ifstream tin;
    ofstream tout;
    tin.open("coursesreg.dat", ios::in | ios::binary);
    if (!tin)
        cout << "File not found";
    else
    {
        tout.open("new.dat", ios::out | ios::binary);
        tin.read((char *)&id, sizeof(int));
        tin.read((char *)&courseCode, sizeof(string));
        while (!tin.eof())
        {
            if (Ccode != courseCode)
            {
                tin.read((char *)&id, sizeof(int));
                tout.write((char *)&courseCode, sizeof(string));
            }

            tin.read((char *)&id, sizeof(int));
            tin.read((char *)&courseCode, sizeof(string));
        }
        tin.close();
        tout.close();
        remove("coursesreg.dat");
        rename("new.dat", "coursesreg.dat");
        cout << "\n\t\tCourse has been successfully deleted!\n";
    }
}
// SEARCH COURSE
void Course::findCourse(string &Ccode)
{
    int counter = 0;
    ifstream fin;
    fin.open("courses.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\nFile not found";
    else
    {
        fin.read((char *)&nameOfTheCourse, sizeof(string));
        fin.read((char *)&courseCode, sizeof(string));
        fin.read((char *)&profname, sizeof(string));
        fin.read((char *)&proflastname, sizeof(string));
        while (!fin.eof())
        {
            if (Ccode == courseCode)
            {
                showCourseData();
                counter++;
            }
            fin.read((char *)&nameOfTheCourse, sizeof(string));
            fin.read((char *)&courseCode, sizeof(string));
            fin.read((char *)&profname, sizeof(string));
            fin.read((char *)&proflastname, sizeof(string));
        }
        if (counter == 0)
            cout << "\t\tCourse is not found\n\n";
        fin.close();
    }
}