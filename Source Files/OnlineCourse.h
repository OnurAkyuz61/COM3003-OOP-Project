// Include Guard
#pragma once 

#include <iostream> // Include the iostream library
#include <string> // Include the string library

using namespace std; // Use the standard namespace

class OnlineCourse { // OnlineCourse class
protected: // Protected members
    string courseName, instructor, level, prerequisites; // Course name, instructor, level, and prerequisites
    int totalCapacity, enrolledStudents, duration; // Total capacity, enrolled students, and duration
    double price, discountRate, totalRating; // Price, discount rate, and total rating
    int ratingCount; // Rating count

public: // Public members
    OnlineCourse(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration); // Constructor
    virtual void displayInfo() = 0; // Display the course information
    virtual bool addStudent() = 0; // Add a student to the course
    virtual bool checkCapacity() = 0; // Check if the course is full
    double getPrice() const; // Get the price of the course
    string getCourseName() const; // Get the course name
    double getAverageRating() const; // Get the average rating of the course
    void rateCourse(int rating); // Rate the course
    virtual ~OnlineCourse() {} // Destructor
};