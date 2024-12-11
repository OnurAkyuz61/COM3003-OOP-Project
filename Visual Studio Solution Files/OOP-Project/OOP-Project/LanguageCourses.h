// Include Guard
#pragma once

#include "OnlineCourse.h" // OnlineCourse

using namespace std; // std::vector

class LanguageCourses : public OnlineCourse { // LanguageCourses class
private: // Private members
    string language; // Language of the course
    bool nativeSpeaker; // Whether the student is a native speaker

public: // Public members
    LanguageCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string language, bool nativeSpeaker); // Constructor
    void displayInfo() override; // Display the course information
    bool addStudent() override; // Add a student to the course
    bool checkCapacity() override; // Check if the course is full
};