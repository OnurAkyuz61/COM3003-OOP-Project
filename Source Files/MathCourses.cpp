#include "MathCourses.h"

MathCourses::MathCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur, string area) : OnlineCourse(name, instr, capacity, pr, lvl, discRate, prereq, dur), focusArea(area) {}

void MathCourses::displayInfo() {
    cout << "Math Course: " << courseName << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Level: " << level << endl;
    cout << "Price: $" << fixed << setprecision(2) << price << endl;
    cout << "Discount Rate: " << discountRate << "%" << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Duration: " << duration << " hours" << endl;
    cout << "Focus Area: " << focusArea << endl;
    cout << "Average Rating: " << fixed << setprecision(2) << getAverageRating() << " / 5" << endl;
    cout << "Enrolled Students: " << enrolledStudents << "/" << totalCapacity << endl << endl;
}

bool MathCourses::addStudent() {
    if (checkCapacity()) {
        enrolledStudents++;
        return true;
    }
    return false;
}

bool MathCourses::checkCapacity() {
    return enrolledStudents < totalCapacity;
}