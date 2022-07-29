// Student class is derived from UniversityMember class
// /inheritance is used
#ifndef STUDENT_H
#define STUDENT_H
#include "UniversityMember.h" // UniversityMember class 
#include <string> // C++ standard string class

class Student: public UniversityMember {
    public:
    Student();
    void getDetails();
    void deleteMember(int &studentID);
    void showMemberData();
    void storeMember();
    void viewMember();
    void searchMember(int &studentID);

    void studentAuthorize();
    void studentRegister(int &studentID);
    void getRegisterData();
    int storeRegisterData();
    void usernamepassCheck(std::string &username, std::string &pass);
    void studentLoginEnter();
    void studentIDEnter();
    void deleteAccount(int &studentID);
    void studentAuthorizeChoice(int &choice);

    void Status(int &status);

    protected:
    int studentId;
};

#endif