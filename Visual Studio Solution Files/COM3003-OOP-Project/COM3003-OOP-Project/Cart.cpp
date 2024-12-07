﻿#include "Cart.h" // Include the header file

// Default constructor
void Cart::addToCart(OnlineCourse* course) {
    cart.push_back(course); // Add the course to the cart
    cout << course->getCourseName() << " has been added to your cart." << endl; // Display a message indicating that the course has been added to the cart
}

// Display the cart contents
void Cart::displayCart() {
    if (cart.empty()) {  // Check if the cart is empty
        cout << "Your cart is empty." << endl; // Display a message indicating that the cart is empty
        return; // Exit the function
    }

    cout << "Courses in your cart:" << endl; // Display a message indicating that the courses in the cart will be displayed
    for (size_t i = 0; i < cart.size(); ++i) { // Loop through the cart
        cout << i + 1 << ". " << cart[i]->getCourseName() << " - ₺" << fixed << setprecision(2) << cart[i]->getPrice() << endl; // Display the course name and price
    }
}

void Cart::checkout() { // Checkout function
    if (cart.empty()) { // Check if the cart is empty
        cout << "Your cart is empty. Nothing to checkout." << endl; // Display a message indicating that the cart is empty
        return; // Exit the function
    }

    cout << "Checking out the following courses:" << endl; // Display a message indicating that the courses will be checked out
    for (OnlineCourse* course : cart) { // Loop through the cart
        cout << "- " << course->getCourseName() << " (₺" << fixed << setprecision(2) << course->getPrice() << ")" << endl; // Display the course name and price
        purchasedCourses.push_back(course); // Add the course to the purchased courses list
    }
    cart.clear(); // Clear the cart
    cout << "Checkout complete! Thank you for your purchase." << endl; // Display a message indicating that the checkout is complete
}

void Cart::displayPurchasedCourses() { // Display purchased courses function
    if (purchasedCourses.empty()) { // Check if the purchased courses list is empty
        cout << "You haven't purchased any courses yet." << endl; // Display a message indicating that the purchased courses list is empty
        return; // Exit the function
    }

    cout << "Your purchased courses:" << endl; // Display a message indicating that the purchased courses will be displayed
    for (size_t i = 0; i < purchasedCourses.size(); ++i) { // Loop through the purchased courses list
        cout << i + 1 << ". " << purchasedCourses[i]->getCourseName() << endl; // Display the course name
        cout << "   Price: ₺" << fixed << setprecision(2) << purchasedCourses[i]->getPrice() << endl; // Display the course price
        cout << "   Average Rating: " << fixed << setprecision(2) << purchasedCourses[i]->getAverageRating() << " / 5" << endl; // Display the average rating
    }
}