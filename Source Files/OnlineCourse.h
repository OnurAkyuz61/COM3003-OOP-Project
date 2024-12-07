// include guard
#ifndef ONLINECOURSE_H

// header guard
#define ONLINECOURSE_H

#include <iostream> // for cout
#include <string> // for string
#include <iomanip> // For setprecision

using namespace std; // using namespace std

class OnlineCourse { // class OnlineCourse
protected: // protected members
    string courseName, instructor, level, prerequisites; // string for course name, instructor, level, and prerequisites
    int totalCapacity, enrolledStudents, duration; // int for total capacity, enrolled students, and duration
    double price, discountRate, totalRating; // double for price, discount rate, and total rating
    int ratingCount; // int for rating count

public: // public members
    OnlineCourse(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration); // constructor
    virtual void displayInfo() = 0; // pure virtual function to display the info
    virtual bool addStudent() = 0; // pure virtual function to add a student
    virtual bool checkCapacity() = 0; // pure virtual function to check the capacity
    double getPrice() const; // function to get the price
    double getDiscountRate() const; // function to get the discount rate
    string getCourseName() const; // function to get the course name
    double getAverageRating() const; // function to get the average rating
    void rateCourse(int rating); // function to rate the course
    virtual ~OnlineCourse() {} // virtual destructor
};

#endif // ONLINECOURSE_H