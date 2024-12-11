#pragma once

#include "OnlineCourse.h"

using namespace std;

class LanguageCourses : public OnlineCourse {
private:
    string language;
    bool nativeSpeaker;

public:
    LanguageCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string language, bool nativeSpeaker);
    void displayInfo() override;
    bool addStudent() override;
    bool checkCapacity() override;
};