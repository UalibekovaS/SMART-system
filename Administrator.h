// Administrator class is derived from UniversityMember class
// /inheritance is used

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "UniversityMember.h" // UniversityMember class declaration
#include <string>             // C++ standard string class

class Administrator : public UniversityMember
{
public:
    Administrator();
    void getDetails();
    void storeMember();
    void addNewMember(int &choice);
    void showMember(int &choice);
    void deleteMember(int &choice);
    void searchMember(int &choice);
    void administratorLogin();
    void adminStatus(int &status);
    void addCourse();
    void deleteCourse(const std::string &courseCode);
private:
    std::string username;
    std::string password;
};

#endif