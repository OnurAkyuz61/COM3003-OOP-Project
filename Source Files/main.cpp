#include "SoftwareCourses.h"
#include "MathCourses.h"
#include "ProfessionalDevelopmentCourses.h"
#include "LanguageCourses.h"
#include "Cart.h"
#include <map>

bool login(const map<string, string>& studentDatabase) {
    string studentNumber, password;
    cout << "Enter Student Number: ";
    cin >> studentNumber;
    cout << "Enter Password: ";
    cin >> password;

    if (studentDatabase.find(studentNumber) != studentDatabase.end() && studentDatabase.at(studentNumber) == password) {
        cout << "Login successful. Welcome, student " << studentNumber << "!" << endl << endl;
        return true;
    }
    cout << "Invalid credentials. Please try again." << endl;
    return false;
}

int main() {
    // Student database with student number and password
    map<string, string> studentDatabase = {
        {"2200005590", "onur"},
        {"2200005798", "esma"},
        {"2300008095", "melisa"}
    };

    // Software Courses
    SoftwareCourses programmingI("Programming I", "Asst. Prof. Oznur Sengel", 20, 149.99 * 27, "Beginner", 10.0, "Basic C Knowledge", 40, "C", "Visual Studio");
    SoftwareCourses programmingII("Programming II", "Asst. Prof. Oznur Sengel", 20, 149.99 * 27, "Intermediate", 10.0, "Basic C Knowledge", 40, "C", "Visual Studio");
    SoftwareCourses oop("Object Oriented Programming", "Assoc. Prof. Fatma Patlar Akbulut", 20, 149.99 * 27, "Intermediate", 10.0, "Basic C++ Knowledge", 40, "C++", "Visual Studio");

    // Math Courses
    MathCourses calculusI("Calculus I", "Prof. Dr. Mert Caglar", 30, 99.99 * 27, "Beginner", 5.0, "High School Math", 20, "Differential and Integral Calculus");

    // Professional Development Courses
    ProfessionalDevelopmentCourses pdCourse("Leadership in Tech", "Prof Dr. Akhan Akbulut", 15, 199.99 * 27, "Advanced", 20.0, "None", 30, true, "Leadership, Communication, Conflict Resolution");

    // Language Courses
    LanguageCourses englishCourse("English for Business", "Lect. Ebru Temiz", 25, 129.99 * 27, "Intermediate", 15.0, "None", 20, "English", true);

    // Available Courses
    vector<OnlineCourse*> availableCourses = { &programmingI, &programmingII, &oop, &calculusI, &pdCourse, &englishCourse };

    cout << "**********************************************" << endl;
    cout << "* Welcome to the Online Course Management!  *" << endl;
    cout << "**********************************************" << endl << endl;

    bool loggedIn = false;
    while (!loggedIn) {
        loggedIn = login(studentDatabase);
    }

    Cart cart;

    while (loggedIn) {
        cout << endl;
        cout << "1. View Available Courses" << endl;
        cout << "2. Add Course to Cart" << endl;
        cout << "3. View Cart" << endl;
        cout << "4. Checkout" << endl;
        cout << "5. View Purchased Courses and Rate" << endl;
        cout << "6. Logout" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Available Courses:" << endl;
            for (size_t i = 0; i < availableCourses.size(); ++i) {
                availableCourses[i]->displayInfo();
            }
            break;

        case 2: {
            cout << "Enter the course number to add to cart: ";
            int courseNumber;
            cin >> courseNumber;

            if (courseNumber < 1 || courseNumber > availableCourses.size()) {
                cout << "Invalid course number." << endl;
            }
            else {
                cart.addToCart(availableCourses[courseNumber - 1]);
            }
            break;
        }

        case 3:
            cart.displayCart();
            break;

        case 4:
            cart.checkout();
            break;

        case 5:
            cart.displayPurchasedCourses();
            break;

        case 6:
            loggedIn = false;
            cout << "Logged out successfully." << endl;
            break;

        case 7:
            cout << "Exiting program. Thank you for using the Online Course Management System!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}