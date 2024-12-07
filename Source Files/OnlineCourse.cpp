#include "OnlineCourse.h" // Include the header file

OnlineCourse::OnlineCourse(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur) : courseName(name), instructor(instr), totalCapacity(capacity), price(pr), level(lvl), discountRate(discRate), prerequisites(prereq), duration(dur), enrolledStudents(0), totalRating(0), ratingCount(0) {} // Constructor

double OnlineCourse::getPrice() const { // Get price function
    return price; // Return the price
}

double OnlineCourse::getDiscountRate() const { // Get discount rate function
    return discountRate; // Return the discount rate
}

string OnlineCourse::getCourseName() const { // Get course name function
    return courseName;
}

double OnlineCourse::getAverageRating() const { // Get average rating function
    return ratingCount > 0 ? totalRating / ratingCount : 0.0; // Return the average rating if there are ratings, otherwise return 0.0
}

void OnlineCourse::rateCourse(int rating) { // Rate course function
    if (rating >= 1 && rating <= 5) { // Check if the rating is valid
        totalRating += rating; // Add the rating to the total rating
        ratingCount++; // Increment the rating count
        cout << "Thank you for rating the course!" << endl; // Display a message indicating that the rating has been received
    }
    else { // If the rating is invalid
        cout << "Invalid rating. Please enter a number between 1 and 5." << endl; // Display an error message
    }
}