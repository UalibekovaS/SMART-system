// Professor class is derived from UniversityMember class
// inheritance is used

#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "UniversityMember.h" // UniversityMember class
#include <string>             // C++ standard string class
class Professor : public UniversityMember
{
public:
    Professor();
    void getDetails();
    void deleteMember(std::string &eMail);
    void showMemberData();
    void storeMember();
    void viewMember();
    void searchMember(std::string &eMail);
    void Status(int &status);

    // functions connected with registration and login
    void professorAuthorize();
    void professorRegister(std::string &eMail);
    void getRegisterData();
    void usernamepassCheckProf(std::string &username, std::string &pass);
    void professorLoginEnter();
    void professorEmailEnter();
    void deleteAccountProf(std::string &eMail);
    void professorAuthorizeChoice(int &choice);

    bool is_valid(std::string &email); // to validate the email

private:
    std::string email;
};

#endif