#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "UniversityMember.h"
using namespace std;

UniversityMember::UniversityMember()
{
}
void UniversityMember::getDetails()
{
}

void UniversityMember::storeMember()
{
}

// Function to check the character
// is an alphabet or not
bool UniversityMember::isChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// To check the validity of first name and last name
