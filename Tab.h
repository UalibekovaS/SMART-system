// Tab class is derived from UniversityMember class
// /inheritance is used

#ifndef TAB_H
#define TAB_H
#include <string> // C++ standard string class
#include "Professor.h"

class Tab {
    public:
    void main_menu();
    void administratorTab();
    void studentTab();
    void professorTab();
    void adminTabOperations(int &operation);
    void mainTabOperations(int &status);
    protected:
};

#endif