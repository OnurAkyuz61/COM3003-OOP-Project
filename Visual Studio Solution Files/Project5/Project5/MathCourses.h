#ifndef MATHCOURSES_H
#define MATHCOURSES_H

#include "OnlineCourse.h"

class MathCourses : public OnlineCourse {
private:
    string focusArea;

public:
    MathCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur, string area);
    void displayInfo() override;
    bool addStudent() override;
    bool checkCapacity() override;
};

#endif // MATHCOURSES_H