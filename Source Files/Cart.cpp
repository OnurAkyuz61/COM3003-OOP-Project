#include "Cart.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Cart::addToCart(OnlineCourse* course) {
    cart.push_back(course);
    cout << course->getCourseName() << " has been added to your cart." << endl;
}

void Cart::displayCart() {
    if (cart.empty()) {
        cout << "Your cart is empty." << endl;
        return;
    }
    cout << "Courses in your cart:" << endl;
    for (size_t i = 0; i < cart.size(); ++i) {
        cout << i + 1 << ". " << cart[i]->getCourseName() << " - " << cart[i]->getPrice() << " TL" << endl;
    }
}

void Cart::checkout() {
    if (cart.empty()) {
        cout << "Your cart is empty. Nothing to checkout." << endl;
        return;
    }

    string cardNumber, expiryDate, cvv;

    cout << "Please enter your payment details (simulated):" << endl;
    cout << "Enter Card Number: ";
    cin >> cardNumber;
    cout << "Enter Expiry Date (MM/YY): ";
    cin >> expiryDate;
    cout << "Enter CVV: ";
    cin >> cvv;

    cout << "Payment successfully. Thank you for your purchase! (simulated)" << endl;

    for (OnlineCourse* course : cart) {
        purchasedCourses.push_back(course);
    }

    cart.clear();
}

void Cart::displayPurchasedCourses() {
    if (purchasedCourses.empty()) {
        cout << "You haven't purchased any courses yet." << endl;
        return;
    }
    cout << "Your purchased courses:" << endl;
    for (size_t i = 0; i < purchasedCourses.size(); ++i) {
        cout << i + 1 << ". " << purchasedCourses[i]->getCourseName() << endl;
        cout << "   Price: " << purchasedCourses[i]->getPrice() << " TL" << endl;
        cout << "   Average Rating: " << purchasedCourses[i]->getAverageRating() << " / 5" << endl;
    }
}

void Cart::rateCourse() {
    if (purchasedCourses.empty()) {
        cout << "You have no courses to rate." << endl;
        return;
    }
    cout << "Select a course to rate:" << endl;
    for (size_t i = 0; i < purchasedCourses.size(); ++i) {
        cout << i + 1 << ". " << purchasedCourses[i]->getCourseName() << endl;
    }
    int choice;
    cin >> choice;
    if (choice < 1 || choice > purchasedCourses.size()) {
        cout << "Invalid choice." << endl;
        return;
    }
    int rating;
    cout << "Enter your rating (1-5): ";
    cin >> rating;
    if (rating >= 1 && rating <= 5) {
        purchasedCourses[choice - 1]->rateCourse(rating);
    }
    else {
        cout << "Invalid rating. Please try again." << endl;
    }
}
