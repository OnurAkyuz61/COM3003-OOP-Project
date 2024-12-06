#include "SoftwareCourses.h"
#include "MathCourses.h"
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
    cout << "**********************************************" << endl;
    cout << "* Welcome to the Online Course Management!  *" << endl;
    cout << "**********************************************" << endl << endl;

    map<string, string> studentDatabase = {
        {"2200005590", "onur"},
        {"2200005798", "esma"},
        {"2300008095", "melisa"}
    };

    SoftwareCourses cppCourse("Advanced C++ Programming", "Alice Johnson", 20, 149.99, "Intermediate", 10.0, "Basic C++ Knowledge", 40, "C++", "Visual Studio");
    SoftwareCourses pythonCourse("Python for Data Science", "John Smith", 25, 129.99, "Beginner", 15.0, "None", 35, "Python", "Jupyter Notebook");
    MathCourses calculusCourse("Calculus 101", "Dr. Emily Brown", 30, 99.99, "Beginner", 5.0, "High School Math", 20, "Differential and Integral Calculus");

    vector<OnlineCourse*> availableCourses = { &cppCourse, &pythonCourse, &calculusCourse };

    Cart cart;

    while (true) {
        bool loggedIn = false;

        while (!loggedIn) {
            loggedIn = login(studentDatabase);
        }

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
                    cout << i + 1 << ". ";
                    availableCourses[i]->displayInfo();
                }
                break;

            case 2: {
                cout << "Enter the course number to add to cart: ";
                int courseNumber;
                cin >> courseNumber;

                if (courseNumber > 0 && courseNumber <= (int)availableCourses.size()) {
                    cart.addToCart(availableCourses[courseNumber - 1]);
                }
                else {
                    cout << "Invalid course number." << endl;
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
                cout << "Thank you for using the Online Course Management System!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
}