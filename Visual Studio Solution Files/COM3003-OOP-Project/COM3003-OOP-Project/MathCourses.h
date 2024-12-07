// include guard
#ifndef MATHCOURSES_H

// header guard
#define MATHCOURSES_H

#include "OnlineCourse.h" // for OnlineCourse

class MathCourses : public OnlineCourse { // class MathCourses
private: // private members
    string focusArea; // string for focus area

public: // public members
    MathCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string focusArea); // constructor
    void displayInfo() override; // function to display the info
    bool addStudent() override; // function to add a student
    bool checkCapacity() override; // function to check the capacity
};

#endif // MATHCOURSES_H