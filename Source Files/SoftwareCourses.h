#ifndef SOFTWARECOURSES_H
#define SOFTWARECOURSES_H

#include "OnlineCourse.h"

class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage, devEnvironment;

public:
    SoftwareCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string programmingLanguage, string devEnvironment);
    void displayInfo() override;
    bool addStudent() override;
    bool checkCapacity() override;
};

#endif // SOFTWARECOURSES_H