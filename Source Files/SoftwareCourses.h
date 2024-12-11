// Include Guard
#pragma once

#include "OnlineCourse.h" // OnlineCourse

using namespace std; // Use the standard namespace

class SoftwareCourses : public OnlineCourse { // SoftwareCourses class
private: // Private members
    string programmingLanguage; // Programming language of the course
    string devEnvironment; // Development environment of the course

public: // Public members
    SoftwareCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string programmingLanguage, string devEnvironment); // Constructor
    void displayInfo() override; // Display the course information
    bool addStudent() override; // Add a student to the course
    bool checkCapacity() override; // Check if the course is full
};