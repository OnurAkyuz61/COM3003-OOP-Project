#include "SoftwareCourses.h" // Include the header file
#include "MathCourses.h" // Include the header file
#include "ProfessionalDevelopmentCourses.h" // Include the header file
#include "LanguageCourses.h" // Include the header file
#include "Cart.h" // Include the header file
#include <map> // Include the map library

bool login(const map<string, string>& studentDatabase) { // Login function
    string studentNumber, password; // Declare variables for student number and password
    cout << "Enter Student Number: "; // Prompt the user to enter the student number
    cin >> studentNumber; // Read the student number from the user
    cout << "Enter Password: "; // Prompt the user to enter the password
    cin >> password; // Read the password from the user

    if (studentDatabase.find(studentNumber) != studentDatabase.end() && studentDatabase.at(studentNumber) == password) { // Check if the student number and password match
        cout << "Login successful. Welcome, student " << studentNumber << "!" << endl << endl; // Display a welcome message
        return true; // Return true to indicate successful login
    }
    cout << "Invalid credentials. Please try again." << endl; // Display an error message
    return false; // Return false to indicate failed login
}

int main() { // Main function
    // Student database with student number and password
    map<string, string> studentDatabase = { // Create a map of student numbers and passwords
        {"2200005590", "onur"}, // Student number and password for student 1
        {"2200005798", "esma"}, // Student number and password for student 2
        {"2300008095", "melisa"} // Student number and password for student 3
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

    //Welcome Message
    cout << "**********************************************" << endl;
    cout << "* Welcome to the Online Course Management!  *" << endl;
    cout << "**********************************************" << endl << endl;

    bool loggedIn = false; // Declare a boolean variable to track if the user is logged in
    while (!loggedIn) { // Loop until the user is logged in
        loggedIn = login(studentDatabase); // Call the login function and set the loggedIn variable to the returned value
    }

    Cart cart; // Create a Cart object

    while (loggedIn) { // Loop until the user logs out
        cout << endl; // Print a new line
        cout << "1. View Available Courses" << endl; // Print the first option
        cout << "2. Add Course to Cart" << endl; // Print the second option
        cout << "3. View Cart" << endl; // Print the third option
        cout << "4. Checkout" << endl; // Print the fourth option
        cout << "5. View Purchased Courses and Rate" << endl; // Print the fifth option
        cout << "6. Logout" << endl; // Print the sixth option
        cout << "7. Exit" << endl; // Print the seventh option
        cout << "Enter your choice: "; // Prompt the user to enter their choice
        int choice; // Declare an integer variable to store the user's choice
        cin >> choice; // Read the user's choice from the user

        switch (choice) { // Switch statement based on the user's choice
        case 1: // Case 1: View Available Courses    
            cout << "Available Courses:" << endl; // Print a message     
            for (size_t i = 0; i < availableCourses.size(); ++i) { // Loop through the available courses
                availableCourses[i]->displayInfo(); // Display the information of each course
            }
            break; // Break out of the switch statement

        case 2: { // Case 2: Add Course to Cart
            cout << "Enter the course number to add to cart: "; // Prompt the user to enter the course number
            int courseNumber; // Declare an integer variable to store the course number
            cin >> courseNumber; // Read the course number from the user

            if (courseNumber < 1 || courseNumber > availableCourses.size()) { // Check if the course number is valid
                cout << "Invalid course number." << endl; // Display an error message
            }
            else { // Otherwise
                cart.addToCart(availableCourses[courseNumber - 1]); // Add the course to the cart
            }
            break; // Break out of the switch statement
        }

        case 3: // Case 3: View Cart
            cart.displayCart(); // Display the contents of the cart
            break; // Break out of the switch statement

        case 4: // Case 4: Checkout
            cart.checkout(); // Checkout the courses in the cart
            break; // Break out of the switch statement

        case 5: // Case 5: View Purchased Courses and Rate
            cart.displayPurchasedCourses(); // Display the purchased courses and their ratings
            break; // Break out of the switch statement

        case 6: // Case 6: Logout
            loggedIn = false; // Set the loggedIn variable to false to log out
            cout << "Logged out successfully." << endl; // Display a logout message
            break; // Break out of the switch statement

        case 7: // Case 7: Exit
            cout << "Exiting program. Thank you for using the Online Course Management System!" << endl; // Display an exit message
            return 0; // Return 0 to indicate successful exit

        default: // Default case: Invalid choice
            cout << "Invalid choice. Please try again." << endl; // Display an error message
        }
    }
    return 0; // Return 0 to indicate successful exit
}