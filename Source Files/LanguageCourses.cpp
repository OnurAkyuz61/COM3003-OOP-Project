#include "LanguageCourses.h"

LanguageCourses::LanguageCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string language, bool nativeSpeaker) : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), language(language), nativeSpeaker(nativeSpeaker) {}

void LanguageCourses::displayInfo() {
    cout << "Language Course: " << courseName << endl;
    cout << "Instructor: " << instructor << endl;
    cout << "Level: " << level << endl;
    cout << "Price: ₺" << fixed << setprecision(2) << price << endl;
    cout << "Discount Rate: " << discountRate << "%" << endl;
    cout << "Prerequisites: " << prerequisites << endl;
    cout << "Duration: " << duration << " hours" << endl;
    cout << "Language: " << language << endl;
    cout << "Native Speaker: " << (nativeSpeaker ? "Yes" : "No") << endl;
    cout << "Average Rating: " << fixed << setprecision(2) << getAverageRating() << " / 5" << endl;
    cout << "Enrolled Students: " << enrolledStudents << "/" << totalCapacity << endl << endl;
}

bool LanguageCourses::addStudent() {
    if (checkCapacity()) {
        enrolledStudents++;
        return true;
    }
    return false;
}

bool LanguageCourses::checkCapacity() {
    return enrolledStudents < totalCapacity;
}