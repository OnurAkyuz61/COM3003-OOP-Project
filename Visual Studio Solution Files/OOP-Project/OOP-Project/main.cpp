#include "SoftwareCourses.h" // Include the header file
#include "MathCourses.h" // Include the header file
#include "ProfessionalDevelopmentCourses.h" // Include the header file
#include "LanguageCourses.h" // Include the header file
#include "Cart.h" // Include the header file
#include <map> // Include the map library
#include <iostream> // Include the iostream library
using namespace std; // Use the standard namespace

bool login(const map<string, string>& studentDatabase) { // Login function
    cout << "**********************************************" << endl;
    cout << "* Welcome to the Online Course Management!  *" << endl;
    cout << "**********************************************" << endl;

    string studentNumber, password; // Declare variables for student number and password
    cout << "Enter Student Number: "; // Prompt the user to enter their student number
    cin >> studentNumber; // Read the student number from the input
    cout << "Enter Password: "; // Prompt the user to enter their password
    cin >> password; // Read the password from the input

    if (studentDatabase.find(studentNumber) != studentDatabase.end() && studentDatabase.at(studentNumber) == password) { // Check if the student number and password are valid
        cout << "Login successful. Welcome, student " << studentNumber << "!" << endl << endl; // Display a welcome message
        return true; // Return true to indicate that the login was successful
    }
    cout << "Invalid credentials. Please try again." << endl; // Display an error message
    return false; // Return false to indicate that the login was unsuccessful
}

int main() { // Main function
    map<string, string> studentDatabase = { // Define the student database
        {"2200005590", "onur"},
        {"2200005798", "esma"},
        {"2300008095", "melisa"}
    };

    SoftwareCourses programmingI("Programming I", "Asst. Prof. Oznur Sengel", 20, 149.99, "Beginner", 10.0, "Basic C Knowledge", 40, "C", "Visual Studio"); // Define a programming I course
    SoftwareCourses programmingII("Programming II", "Asst. Prof. Oznur Sengel", 20, 149.99, "Intermediate", 10.0, "Basic C Knowledge", 40, "C", "Visual Studio"); // Define a programming II course
    MathCourses calculusI("Calculus I", "Prof. Dr. Mert Caglar", 30, 99.99, "Beginner", 5.0, "High School Math", 20, "Differential and Integral Calculus"); // Define a calculus I course
    ProfessionalDevelopmentCourses pdCourse("Leadership in Tech", "Prof Dr. Akhan Akbulut", 15, 199.99, "Advanced", 20.0, "None", 30, true, "Leadership, Communication, Conflict Resolution"); // Define a professional development course
    LanguageCourses englishCourse("English for Business", "Lect. Ebru Temiz", 25, 129.99, "Intermediate", 15.0, "None", 20, "English", true); // Define an English for business course

    vector<OnlineCourse*> availableCourses = { &programmingI, &programmingII, &calculusI, &pdCourse, &englishCourse }; // Define the available courses

    while (true) { // Main loop
        bool loggedIn = false; // Declare a variable to track if the user is logged in
        while (!loggedIn) { // Login loop
            loggedIn = login(studentDatabase); // Call the login function and set the loggedIn variable to the returned value
        }

        Cart cart; // Declare a cart object

        while (loggedIn) { // Main menu loop
            cout << endl; // Print a new line
            cout << "1. View Available Courses" << endl; // Print the first menu option
            cout << "2. Add Course to Cart" << endl; // Print the second menu option
            cout << "3. View Cart" << endl; // Print the third menu option
            cout << "4. Checkout" << endl; // Print the fourth menu option
            cout << "5. View Purchased Courses" << endl; // Print the fifth menu option
            cout << "6. Rate Purchased Courses" << endl; // Print the sixth menu option
            cout << "7. Logout" << endl; // Print the seventh menu option
            cout << "8. Exit" << endl; // Print the eighth menu option
            cout << "Enter your choice: "; // Prompt the user to enter their choice
            int choice; // Declare a variable to store the user's choice
            cin >> choice; // Read the user's choice from the input

            switch (choice) { // Switch statement to handle the user's choice
            case 1: // View available courses
                cout << "Available Courses:" << endl; // Print a message indicating that the available courses will be displayed
                for (auto course : availableCourses) { // Loop through the available courses
                    course->displayInfo(); // Display the course information
                }
                break; // Exit the switch statement

            case 2: // Add course to cart
                cout << "Add Course to Cart:" << endl; // Print a message indicating that the course will be added to the cart
                for (size_t i = 0; i < availableCourses.size(); ++i) { // Loop through the available courses
                    cout << i + 1 << ". " << availableCourses[i]->getCourseName() << endl; // Print the course number and name
                }
                int courseNumber; // Declare a variable to store the user's choice
                cin >> courseNumber; // Read the user's choice from the input
                if (courseNumber < 1 || courseNumber > availableCourses.size()) { // Check if the user's choice is valid
                    cout << "Invalid course number." << endl; // Display an error message
                }
                else { // Otherwise
                    cart.addToCart(availableCourses[courseNumber - 1]); // Add the selected course to the cart
                } 
                break; // Exit the switch statement

            case 3: // View cart
                cart.displayCart(); // Display the cart contents
                break; // Exit the switch statement

            case 4: // Checkout
                cart.checkout(); // Checkout the cart
                break; // Exit the switch statement

            case 5: // View purchased courses
                cart.displayPurchasedCourses(); // Display the purchased courses
                cart.rateCourse(); // Rate the purchased courses
                break; // Exit the switch statement

            case 6: // Rate purchased courses
                cart.rateCourse(); // Rate the purchased courses
                break; // Exit the switch statement

            case 7: // Logout
                loggedIn = false; // Set the loggedIn variable to false to log out
                cout << "Logged out successfully. Returning to login screen..." << endl; // Display a message indicating that the user is logged out
                break; // Exit the switch statement

            case 8: // Exit
                cout << "Exiting program. Thank you for using the Online Course Management System!" << endl; // Display a message indicating that the program is exiting
                return 0; // Exit the program

            default: // Invalid choice
                cout << "Invalid choice. Please try again." << endl; // Display an error message
            }
        }
    }
    return 0; // Exit the program
}