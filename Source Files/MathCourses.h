#pragma once

#include "OnlineCourse.h"

using namespace std;

class MathCourses : public OnlineCourse {
private:
    string focusArea;

public:
    MathCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string focusArea);
    void displayInfo() override;
    bool addStudent() override;
    bool checkCapacity() override;
};