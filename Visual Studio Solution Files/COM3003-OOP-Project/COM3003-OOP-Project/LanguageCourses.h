// include guard
#ifndef LANGUAGECOURSES_H 

// header guard
#define LANGUAGECOURSES_H

#include "OnlineCourse.h" // for OnlineCourse

class LanguageCourses : public OnlineCourse { // class LanguageCourses
private: // private members
    string language; // string for language
    bool nativeSpeaker; // boolean for native speaker

public: // public members
    LanguageCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string language, bool nativeSpeaker); // constructor
    void displayInfo() override; // function to display the info
    bool addStudent() override; // function to add a student
    bool checkCapacity() override; // function to check the capacity
};

#endif // LANGUAGECOURSES_H