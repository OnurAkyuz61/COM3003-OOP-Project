#pragma once

#ifndef ONLINECOURSE_H
#define ONLINECOURSE_H

#include <iostream>
#include <string>
#include <iomanip> // For setprecision

using namespace std;

class OnlineCourse {
protected:
    string courseName, instructor, level, prerequisites;
    int totalCapacity, enrolledStudents, duration;
    double price, discountRate, totalRating;
    int ratingCount;

public:
    OnlineCourse(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration);
    virtual void displayInfo() = 0;
    virtual bool addStudent() = 0;
    virtual bool checkCapacity() = 0;
    double getPrice() const;
    double getDiscountRate() const;
    string getCourseName() const;
    double getAverageRating() const;
    void rateCourse(int rating);
    virtual ~OnlineCourse() {}
};

#endif // ONLINECOURSE_H
