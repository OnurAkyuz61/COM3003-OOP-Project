#include "OnlineCourse.h"

OnlineCourse::OnlineCourse(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur)
    : courseName(name), instructor(instr), totalCapacity(capacity), price(pr), level(lvl), discountRate(discRate), prerequisites(prereq), duration(dur), enrolledStudents(0), totalRating(0), ratingCount(0) {}

double OnlineCourse::getPrice() const {
    return price;
}

double OnlineCourse::getDiscountRate() const {
    return discountRate;
}

string OnlineCourse::getCourseName() const {
    return courseName;
}

double OnlineCourse::getAverageRating() const {
    return ratingCount > 0 ? totalRating / ratingCount : 0.0;
}

void OnlineCourse::rateCourse(int rating) {
    if (rating >= 1 && rating <= 5) {
        totalRating += rating;
        ratingCount++;
        cout << "Thank you for rating the course!" << endl;
    }
    else {
        cout << "Invalid rating. Please enter a number between 1 and 5." << endl;
    }
}