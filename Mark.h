#ifndef MARK_H
#define MARK_H
#include <string> // C++ standard string class

class Mark{
    public:
    void getMarkDetails();
    void storeMember();
    void showMarksProf(std::string &coursecode);
    void showMemberData();

    void displayStData();
    void displayMarksStud(int &iD);

    protected:
    int studentId;
    std::string mark;
    std::string courseCode;
};

#endif