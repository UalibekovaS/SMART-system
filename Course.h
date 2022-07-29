#ifndef COURSE_H
#define COURSE_H
#include <string> // C++ standard string class

class Course{
    public:
    void getCourseDetails();
    void removeCourse(std:: string &CourseCode);
    void displayCourses(std::string &name);
    void showCourseData();
    void viewCourses();
    void regCourse(std::string &cCode);
    void courseCodeEnter();
    void checkCourse(std::string &Ccode);
    void getRegDataStudCourse();
    void storeRegDataStudCourse();

    void stCourses(int &id);
    void deleteCourse(std::string &Ccode);
    void findCourse(std::string &Ccode);


    public:
    std::string nameOfTheCourse;
    std::string courseCode;
    std::string profname;
    std::string proflastname;
    int id;
};

#endif