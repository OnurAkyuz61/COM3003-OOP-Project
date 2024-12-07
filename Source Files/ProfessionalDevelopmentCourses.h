// include guard
#ifndef PROFESSIONALDEVELOPMENTCOURSES_H

// header guard
#define PROFESSIONALDEVELOPMENTCOURSES_H

#include "OnlineCourse.h" // for OnlineCourse

class ProfessionalDevelopmentCourses : public OnlineCourse { // class ProfessionalDevelopmentCourses
private: // private members
    bool certification; // boolean for certification
    string topicsCovered; // string for topics covered

public:
    ProfessionalDevelopmentCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, bool certification, string topicsCovered); // constructor
    void displayInfo() override; // function to display the info
    bool addStudent() override; // function to add a student
    bool checkCapacity() override; // function to check the capacity
};

#endif // PROFESSIONALDEVELOPMENTCOURSES_H