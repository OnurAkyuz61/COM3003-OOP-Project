// Include guard
#ifndef SOFTWARECOURSES_H

// header guard
#define SOFTWARECOURSES_H

#include "OnlineCourse.h" // for OnlineCourse

class SoftwareCourses : public OnlineCourse { // class SoftwareCourses
private: // private members
    string programmingLanguage, devEnvironment; // string for programming language and dev environment

public: // public members
    SoftwareCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string programmingLanguage, string devEnvironment); // constructor
    void displayInfo() override; // function to display the info
    bool addStudent() override; // function to add a student
    bool checkCapacity() override; // function to check the capacity
};

#endif // SOFTWARECOURSES_H