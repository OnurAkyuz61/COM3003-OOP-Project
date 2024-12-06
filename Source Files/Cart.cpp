#include "Cart.h"

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
        cout << i + 1 << ". " << cart[i]->getCourseName() << " - ₺" << fixed << setprecision(2) << cart[i]->getPrice() << endl;
    }
}

void Cart::checkout() {
    if (cart.empty()) {
        cout << "Your cart is empty. Nothing to checkout." << endl;
        return;
    }

    cout << "Checking out the following courses:" << endl;
    for (OnlineCourse* course : cart) {
        cout << "- " << course->getCourseName() << " (₺" << fixed << setprecision(2) << course->getPrice() << ")" << endl;
        purchasedCourses.push_back(course);
    }
    cart.clear();
    cout << "Checkout complete! Thank you for your purchase." << endl;
}

void Cart::displayPurchasedCourses() {
    if (purchasedCourses.empty()) {
        cout << "You haven't purchased any courses yet." << endl;
        return;
    }

    cout << "Your purchased courses:" << endl;
    for (size_t i = 0; i < purchasedCourses.size(); ++i) {
        cout << i + 1 << ". " << purchasedCourses[i]->getCourseName() << endl;
        cout << "   Price: ₺" << fixed << setprecision(2) << purchasedCourses[i]->getPrice() << endl;
        cout << "   Average Rating: " << fixed << setprecision(2) << purchasedCourses[i]->getAverageRating() << " / 5" << endl;
    }
}