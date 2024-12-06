#include "SoftwareCourses.h"

SoftwareCourses::SoftwareCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur, string lang, string devEnv)
    : OnlineCourse(name, instr, capacity, pr, lvl, discRate, prereq, dur), programmingLanguage(lang), devEnvironment(devEnv) {}

void SoftwareCourses::displayInfo() {
    cout << "Software Course: " << courseName << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Level: " << level << endl;
    cout << "Price: $" << fixed << setprecision(2) << price << endl;
    cout << "Discount Rate: " << discountRate << "%" << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Duration: " << duration << " hours" << endl;
    cout << "Programming Language: " << programmingLanguage << endl;
    cout << "Development Environment: " << devEnvironment << endl;
    cout << "Average Rating: " << fixed << setprecision(2) << getAverageRating() << " / 5" << endl;
    cout << "Enrolled Students: " << enrolledStudents << "/" << totalCapacity << endl << endl;
}

bool SoftwareCourses::addStudent() {
    if (checkCapacity()) {
        enrolledStudents++;
        return true;
    }
    return false;
}

bool SoftwareCourses::checkCapacity() {
    return enrolledStudents < totalCapacity;
}