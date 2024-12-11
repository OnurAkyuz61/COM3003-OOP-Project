// Include Guard
#pragma once 

#include "OnlineCourse.h" // OnlineCourse

using namespace std; // Use the standard namespace

class MathCourses : public OnlineCourse { // MathCourses class
private: // Private members
    string focusArea; // Focus area of the course

public: // Public members
    MathCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string focusArea); // Constructor
    void displayInfo() override; // Display the course information
    bool addStudent() override; // Add a student to the course
    bool checkCapacity() override; // Check if the course is full
};