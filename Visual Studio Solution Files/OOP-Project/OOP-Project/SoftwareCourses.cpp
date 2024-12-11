#include "SoftwareCourses.h"
#include <iostream>

using namespace std;

SoftwareCourses::SoftwareCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string programmingLanguage, string devEnvironment) : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), programmingLanguage(programmingLanguage), devEnvironment(devEnvironment) {}

void SoftwareCourses::displayInfo() {
    cout << "Software Course: " << courseName << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Level: " << level << endl;
    cout << "Price: " << price << " TL" << endl;
    cout << "Discount Rate: " << discountRate << "%" << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Duration: " << duration << " hours" << endl;
    cout << "Programming Language: " << programmingLanguage << endl;
    cout << "Development Environment: " << devEnvironment << endl;
    cout << "Average Rating: " << getAverageRating() << " / 5" << endl;
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
