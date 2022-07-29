#include <iostream>
#include "Mark.h"
#include "Tab.h"
#include <fstream>
#include <string>
using namespace std;

void Mark::getMarkDetails()
{
    cout << "\n\t\tEnter Student ID: ";
    cin >> this->studentId;
    cout << "\n\t\tEnter Student's mark: ";
    cin >> this->mark;
    cout << "\n\t\tEnter Course code: ";
    cin >> this->courseCode;
    storeMember();
    cout << "\n\t\tYou successfully graded the student!";
}

// SHOW THE STUDENT DATA FUNCTION
void Mark::showMemberData()
{
    cout << this->studentId << " \t\t" << this->mark << "\t\t" << this->courseCode << endl
         << endl;
}

// SAVE THE MARKS DATA IN MARKS.DAT FILE FUNCTION
void Mark::storeMember()
{
    ofstream fout;
    fout.open("marks.dat", ios::app | ios::binary);
    fout.write((char *)&studentId, sizeof(int));
    fout.write((char *)&mark, sizeof(string));
    fout.write((char *)&courseCode, sizeof(string));
    fout.close();
}

// DISPLAYING MARKS IN PROFESSOR TAB
void Mark::showMarksProf(string &coursecode)
{
    int counter = 0;
    ifstream fin;
    fin.open("marks.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\nFile not found";
    else
    {
        fin.read((char *)&studentId, sizeof(int));
        fin.read((char *)&mark, sizeof(string));
        fin.read((char *)&courseCode, sizeof(string));
        while (!fin.eof())
        {
            if (coursecode == courseCode)
            {
                showMemberData();
                counter++;
            }
            fin.read((char *)&studentId, sizeof(int));
            fin.read((char *)&mark, sizeof(string));
            fin.read((char *)&courseCode, sizeof(string));
        }
        if (counter == 0)
            cout << "\t\tCourse code not found\n\n";
        fin.close();
    }
}
// DISPLAY THE MARKS OF A STUDENT DATA FUNCTION
void Mark::displayStData()
{
    cout << this->mark << "\t\t" << this->courseCode << "\t\t" << this->studentId << endl
         << endl;
}
// DISPLAY MARKS OF A STUDENT
void Mark::displayMarksStud(int &iD)
{
    int counter = 0;
    ifstream fin;
    fin.open("marks.dat", ios::in | ios::binary);
    if (!fin)
        cout << "\nFile not found";
    else
    {
        fin.read((char *)&studentId, sizeof(int));
        fin.read((char *)&mark, sizeof(string));
        fin.read((char *)&courseCode, sizeof(string));
        while (!fin.eof())
        {
            if (iD == studentId)
            {
                displayStData();
                counter++;
            }
            fin.read((char *)&studentId, sizeof(int));
            fin.read((char *)&mark, sizeof(string));
            fin.read((char *)&courseCode, sizeof(string));
        }
        if (counter == 0)
            cout << "\t\t Marks are not found\n\n";
        fin.close();
    }
}
