#ifndef UNIVERSITYMEMBER_H
#define UNIVERSITYMEMBER_H

#include <string>

// UniveristyMember is an abstract class
class UniversityMember
{
public:
    UniversityMember();
    virtual void getDetails() = 0; //pure virtual function
    virtual void storeMember() = 0; //pure virtual function
    bool isChar(char c);

protected:
    std::string firstName;
    std::string lastName;
    std::string userName;
    std::string passWord;

}; // end class UniversityMember

#endif
