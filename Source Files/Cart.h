// Include Guard 
#pragma once

#include <vector> // std::vector
#include "OnlineCourse.h" // OnlineCourse

using namespace std; // std::vector

class Cart { // Cart class
private: // Private members
    vector<OnlineCourse*> cart; // Vector of OnlineCourse pointers
    vector<OnlineCourse*> purchasedCourses; // Vector of OnlineCourse pointers

public: // Public members
    void addToCart(OnlineCourse* course); // Add a course to the cart
    void displayCart(); // Display the contents of the cart
    void checkout(); // Checkout the courses in the cart
    void displayPurchasedCourses(); // Display the purchased courses
    void rateCourse(); // Rate a course
};