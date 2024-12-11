#include "Cart.h" // Include the header file
#include <iostream> // Include the iostream library
#include <iomanip> // Include the iomanip header for formatting

using namespace std; // Use the standard namespace

void Cart::addToCart(OnlineCourse* course) { // Add a course to the cart
    cart.push_back(course); // Add the course to the cart
    cout << course->getCourseName() << " has been added to your cart." << endl; // Display a message indicating that the course has been added to the cart
}

void Cart::displayCart() { // Display the cart contents
    if (cart.empty()) { // Check if the cart is empty
        cout << "Your cart is empty." << endl; // Display a message indicating that the cart is empty
        return; // Exit the function
    } 
    cout << "Courses in your cart:" << endl; // Display a message indicating that the courses in the cart will be displayed
    for (size_t i = 0; i < cart.size(); ++i) { // Loop through the cart
        cout << i + 1 << ". " << cart[i]->getCourseName() << " - " << cart[i]->getPrice() << " TL" << endl; // Display the course name and price
    }
}

void Cart::checkout() { // Checkout function
    if (cart.empty()) { // Check if the cart is empty
        cout << "Your cart is empty. Nothing to checkout." << endl; // Display a message indicating that the cart is empty
        return; // Exit the function
    }

    string cardNumber, expiryDate, cvv; // Declare variables for card number, expiry date, and CVV

    cout << "Please enter your payment details (simulated):" << endl; // Display a message indicating that the user needs to enter their payment details
    cout << "Enter Card Number: "; // Prompt the user to enter their card number
    cin >> cardNumber; // Read the card number from the user
    cout << "Enter Expiry Date (MM/YY): "; // Prompt the user to enter their expiry date
    cin >> expiryDate; // Read the expiry date from the user
    cout << "Enter CVV: "; // Prompt the user to enter their CVV
    cin >> cvv; // Read the CVV from the user

    cout << "Payment successful. Thank you for your purchase! (simulated)" << endl; // Display a message indicating that the payment is successful

    for (OnlineCourse* course : cart) { // Loop through the cart
        if (course->addStudent()) { // Check if the course has a student
            purchasedCourses.push_back(course); // Add the course to the purchased courses list
        }
        else { // If the course does not have a student
            cout << "Failed to enroll in " << course->getCourseName() << ". Course is full." << endl; // Display a message indicating that the course is full
        }
    }

    cart.clear(); // Clear the cart
}



void Cart::displayPurchasedCourses() { // Display purchased courses function
    if (purchasedCourses.empty()) { // Check if the purchased courses list is empty
        cout << "You haven't purchased any courses yet." << endl; // Display a message indicating that the purchased courses list is empty
        return; // Exit the function
    }
    cout << "Your purchased courses:" << endl; // Display a message indicating that the purchased courses will be displayed
    for (size_t i = 0; i < purchasedCourses.size(); ++i) { // Loop through the purchased courses list
        cout << i + 1 << ". " << purchasedCourses[i]->getCourseName() << endl; // Display the course name
        cout << "   Price: " << purchasedCourses[i]->getPrice() << " TL" << endl; // Display the course price
        cout << "   Average Rating: " << purchasedCourses[i]->getAverageRating() << " / 5" << endl; // Display the average rating
    }
}

void Cart::rateCourse() { // Rate a course function
    if (purchasedCourses.empty()) { // Check if the purchased courses list is empty
        cout << "You have no courses to rate." << endl; // Display a message indicating that the purchased courses list is empty
        return; // Exit the function
    }
    cout << "Select a course to rate:" << endl; // Display a message indicating that the user needs to select a course to rate
    for (size_t i = 0; i < purchasedCourses.size(); ++i) { // Loop through the purchased courses list
        cout << i + 1 << ". " << purchasedCourses[i]->getCourseName() << endl; // Display the course name
    }
    int choice; // Declare a variable for the user's choice
    cin >> choice; // Read the user's choice from the input
    if (choice < 1 || choice > purchasedCourses.size()) { // Check if the choice is valid
        cout << "Invalid choice." << endl; // Display an error message
        return; // Exit the function
    }
    int rating; // Declare a variable for the user's rating
    cout << "Enter your rating (1-5): "; // Prompt the user to enter their rating
    cin >> rating; // Read the user's rating from the input
    if (rating >= 1 && rating <= 5) { // Check if the rating is valid
        purchasedCourses[choice - 1]->rateCourse(rating); // Rate the course
    }
    else { // If the rating is invalid
        cout << "Invalid rating. Please try again." << endl; // Display an error message
    }
}