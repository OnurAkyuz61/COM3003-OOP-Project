#ifndef SOFTWARECOURSES_H
#define SOFTWARECOURSES_H

#include "OnlineCourse.h"

class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage, devEnvironment;

public:
    SoftwareCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur, string lang, string devEnv);
    void displayInfo() override;
    bool addStudent() override;
    bool checkCapacity() override;
};

#endif // SOFTWARECOURSES_H