// include guard
#ifndef CART_H 

// header guard
#define CART_H

#include <vector> // for vector
#include "OnlineCourse.h" // for OnlineCourse

class Cart { // class Cart
private: // private members
    vector<OnlineCourse*> cart; // vector of OnlineCourse pointers
    vector<OnlineCourse*> purchasedCourses; // vector of OnlineCourse pointers

public: // public members
    void addToCart(OnlineCourse* course); // function to add a course to the cart
    void displayCart(); // function to display the cart
    void checkout(); // function to checkout
    void displayPurchasedCourses(); // function to display the purchased courses
};

#endif // CART_H