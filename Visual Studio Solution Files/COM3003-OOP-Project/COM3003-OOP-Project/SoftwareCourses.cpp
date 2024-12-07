#include "SoftwareCourses.h" // Include the header file

SoftwareCourses::SoftwareCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string programmingLanguage, string devEnvironment) : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), programmingLanguage(programmingLanguage), devEnvironment(devEnvironment) {} // Constructor

void SoftwareCourses::displayInfo() { // Display information function
    cout << "Software Course: " << courseName << endl; // Display the course name
    cout << "Instructor: " << instructor << endl; // Display the instructor
    cout << "Level: " << level << endl; // Display the level
    cout << "Price: ?" << fixed << setprecision(2) << price << endl; // Display the price
    cout << "Discount Rate: " << discountRate << "%" << endl; // Display the discount rate
    cout << "Prerequisites: " << prerequisites << endl; // Display the prerequisites
    cout << "Duration: " << duration << " hours" << endl; // Display the duration
    cout << "Programming Language: " << programmingLanguage << endl; // Display the programming language
    cout << "Development Environment: " << devEnvironment << endl; // Display the development environment
    cout << "Average Rating: " << fixed << setprecision(2) << getAverageRating() << " / 5" << endl; // Display the average rating
    cout << "Enrolled Students: " << enrolledStudents << "/" << totalCapacity << endl << endl; // Display the enrolled students and total capacity
}

bool SoftwareCourses::addStudent() { // Add student function
    if (checkCapacity()) { // Check if the course is full
        enrolledStudents++; // Increment the enrolled students count
        return true; // Return true to indicate success
    }
    return false; // Return false to indicate failure
}

bool SoftwareCourses::checkCapacity() { // Check capacity function
    return enrolledStudents < totalCapacity; // Return true if the enrolled students count is less than the total capacity, indicating that the course is not full
}