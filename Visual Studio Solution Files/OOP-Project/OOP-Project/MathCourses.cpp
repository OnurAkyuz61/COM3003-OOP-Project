﻿#include "MathCourses.h"
#include <iostream>

using namespace std;

MathCourses::MathCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string focusArea) : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), focusArea(focusArea) {}

void MathCourses::displayInfo() {
    cout << "Math Course: " << courseName << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Level: " << level << endl;
    cout << "Price: " << price << " TL" << endl;
    cout << "Discount Rate: " << discountRate << "%" << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Duration: " << duration << " hours" << endl;
    cout << "Focus Area: " << focusArea << endl;
    cout << "Average Rating: " << getAverageRating() << " / 5" << endl;
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