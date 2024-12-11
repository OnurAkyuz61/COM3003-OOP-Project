#pragma once

#include "OnlineCourse.h"

using namespace std;

class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage;
    string devEnvironment;

public:
    SoftwareCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string programmingLanguage, string devEnvironment);
    void displayInfo() override;
    bool addStudent() override;
    bool checkCapacity() override;
};