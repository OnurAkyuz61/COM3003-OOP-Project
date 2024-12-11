// Include Guard
#pragma once

#include "OnlineCourse.h" // OnlineCourse

using namespace std; // Use the standard namespace

class ProfessionalDevelopmentCourses : public OnlineCourse { // ProfessionalDevelopmentCourses class
private: // Private members
    bool certification; // Whether the student has a certification
    string topicsCovered; // Topics covered by the course

public: // Public members
    ProfessionalDevelopmentCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, bool certification, string topicsCovered); // Constructor
    void displayInfo() override; // Display the course information
    bool addStudent() override; // Add a student to the course
    bool checkCapacity() override; // Check if the course is full
};