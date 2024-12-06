#include "ProfessionalDevelopmentCourses.h"

ProfessionalDevelopmentCourses::ProfessionalDevelopmentCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, bool certification, string topicsCovered) : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), certification(certification), topicsCovered(topicsCovered) {}

void ProfessionalDevelopmentCourses::displayInfo() {
    cout << "Professional Development Course: " << courseName << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Level: " << level << endl;
    cout << "Price: ₺" << fixed << setprecision(2) << price << endl;
    cout << "Discount Rate: " << discountRate << "%" << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Duration: " << duration << " hours" << endl;
    cout << "Certification: " << (certification ? "Yes" : "No") << endl;
    cout << "Topics Covered: " << topicsCovered << endl;
    cout << "Average Rating: " << fixed << setprecision(2) << getAverageRating() << " / 5" << endl;
    cout << "Enrolled Students: " << enrolledStudents << "/" << totalCapacity << endl << endl;
}

bool ProfessionalDevelopmentCourses::addStudent() {
    if (checkCapacity()) {
        enrolledStudents++;
        return true;
    }
    return false;
}

bool ProfessionalDevelopmentCourses::checkCapacity() {
    return enrolledStudents < totalCapacity;
}