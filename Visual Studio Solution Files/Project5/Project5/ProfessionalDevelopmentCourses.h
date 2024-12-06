#ifndef PROFESSIONALDEVELOPMENTCOURSES_H
#define PROFESSIONALDEVELOPMENTCOURSES_H

#include "OnlineCourse.h"

class ProfessionalDevelopmentCourses : public OnlineCourse {
private:
    bool certification;
    string topicsCovered;

public:
    ProfessionalDevelopmentCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, bool certification, string topicsCovered);
    void displayInfo() override;
    bool addStudent() override;
    bool checkCapacity() override;
};

#endif // PROFESSIONALDEVELOPMENTCOURSES_H