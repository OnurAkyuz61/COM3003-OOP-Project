#include <iostream>
#include <vector>
#include <string>
#include <map> // For storing student login information

using namespace std;

// Abstract base class for all courses
class OnlineCourse {
protected:
    string courseName;        // Name of the course
    string instructor;        // Name of the instructor
    int totalCapacity;        // Total capacity of the course
    int enrolledStudents;     // Number of currently enrolled students
    double price;             // Price of the course
    string level;             // Course level
    double discountRate;      // Discount rate
    string prerequisites;     // Course prerequisites
    int duration;             // Duration of the course in hours

public:
    OnlineCourse(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur) : courseName(name), instructor(instr), totalCapacity(capacity), price(pr), level(lvl), discountRate(discRate), prerequisites(prereq), duration(dur) {
        enrolledStudents = 0; // Initialize enrolled students to zero
    }

    // Pure virtual methods to be implemented by derived classes
    virtual void displayInfo() = 0; // Display course details
    virtual bool addStudent() = 0;  // Add a student to the course
    virtual bool checkCapacity() = 0; // Check if capacity is available

    virtual ~OnlineCourse() {} // Virtual destructor
};

// Derived class for Software Courses
class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage; // Programming language for the course
    string devEnvironment;      // Development environment

public:
    SoftwareCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur, string lang, string devEnv) : OnlineCourse(name, instr, capacity, pr, lvl, discRate, prereq, dur), programmingLanguage(lang), devEnvironment(devEnv) {}

    void displayInfo() override {
        cout << "Software Course: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Level: " << level << endl;
        cout << "Price: $" << price << endl;
        cout << "Discount Rate: " << discountRate << "%" << endl;
        cout << "Prerequisites: " << prerequisites << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
        cout << "Development Environment: " << devEnvironment << endl;
        cout << "Enrolled Students: " << enrolledStudents << "/" << totalCapacity << endl << endl;
    }

    bool addStudent() override {
        if (checkCapacity()) {
            enrolledStudents++;
            return true;
        }
        return false;
    }

    bool checkCapacity() override {
        return enrolledStudents < totalCapacity;
    }
};

// Class to handle course management and student interactions
class CourseManager {
private:
    vector<OnlineCourse*> availableCourses;  // All available courses
    vector<OnlineCourse*> cart;             // Courses added to the cart
    vector<OnlineCourse*> purchasedCourses; // Purchased courses

public:
    // Add a course to the list of available courses
    void addCourse(OnlineCourse* course) {
        availableCourses.push_back(course);
    }

    // Display all available courses
    void displayAvailableCourses() {
        cout << "Available Courses:" << endl;
        for (size_t i = 0; i < availableCourses.size(); ++i) {
            cout << i + 1 << ". ";
            availableCourses[i]->displayInfo();
        }
    }

    // Add a course to the student's cart
    void addToCart(int courseIndex) {
        if (courseIndex < 1 || courseIndex > availableCourses.size()) {
            cout << "Invalid course selection." << endl;
            return;
        }
        OnlineCourse* course = availableCourses[courseIndex - 1];
        if (course->checkCapacity()) {
            cart.push_back(course);
            cout << "Course added to cart!" << endl;
        }
        else {
            cout << "This course is full and cannot be added." << endl;
        }
    }

    // Display the courses in the cart
    void displayCart() {
        cout << "Your Cart:" << endl;
        if (cart.empty()) {
            cout << "No courses in the cart." << endl;
            return;
        }
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << i + 1 << ". ";
            cart[i]->displayInfo();
        }
    }

    // Simulate payment and purchase courses
    void checkout() {
        if (cart.empty()) {
            cout << "No courses in the cart to purchase." << endl;
            return;
        }
        cout << "Enter payment information to proceed (simulated):" << endl;
        string cardNumber;
        cout << "Card Number: ";
        cin >> cardNumber; // Simulated payment process
        cout << "Payment successful!" << endl;
        for (OnlineCourse* course : cart) {
            purchasedCourses.push_back(course);
            course->addStudent();
        }
        cart.clear(); // Clear the cart after purchase
        cout << "Courses purchased successfully!" << endl;
    }

    // Display purchased courses
    void displayPurchasedCourses() {
        cout << "Purchased Courses:" << endl;
        if (purchasedCourses.empty()) {
            cout << "You have not purchased any courses yet." << endl;
            return;
        }
        for (OnlineCourse* course : purchasedCourses) {
            course->displayInfo();
        }
    }
};

// Function for login system
bool login(const map<string, string>& studentDatabase) {
    string studentNumber, password;
    cout << "Enter Student Number: ";
    cin >> studentNumber;
    cout << "Enter Password: ";
    cin >> password;

    // Check credentials
    if (studentDatabase.find(studentNumber) != studentDatabase.end() && studentDatabase.at(studentNumber) == password) {
        cout << "Login successful. Welcome, student " << studentNumber << "!" << endl << endl;
        return true;
    }
    else {
        cout << "Invalid student number or password. Please try again." << endl;
        return false;
    }
}

int main() {
    //Student Database
    map<string, string> studentDatabase = {
        {"2200005590", "password123"},
        {"2200005591", "securepass"},
        {"2200005592", "mypassword"}
    };

    CourseManager manager;

    // Create example courses
    SoftwareCourses cppCourse("Advanced C++ Programming", "Alice Johnson", 20, 149.99, "Intermediate", 10.0, "Basic C++ Knowledge", 40, "C++", "Visual Studio");
    SoftwareCourses pythonCourse("Python for Data Science", "John Smith", 25, 129.99, "Beginner", 15.0, "None", 35, "Python", "Jupyter Notebook");

    // Add courses to the manager
    manager.addCourse(&cppCourse);
    manager.addCourse(&pythonCourse);

    // Login and user interaction loop
    while (true) {
        cout << "Welcome to the Online Course Management System!" << endl;

        bool isLoggedIn = false;
        while (!isLoggedIn) {
            isLoggedIn = login(studentDatabase);
        }

        // Simulated user interface
        while (true) {
            cout << endl;
            cout << "1. View Available Courses" << endl;
            cout << "2. Add Course to Cart" << endl;
            cout << "3. View Cart" << endl;
            cout << "4. Checkout" << endl;
            cout << "5. View Purchased Courses" << endl;
            cout << "6. Logout" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                manager.displayAvailableCourses();
                break;
            case 2:
                cout << "Enter the course number to add to cart: ";
                int courseNumber;
                cin >> courseNumber;
                manager.addToCart(courseNumber);
                break;
            case 3:
                manager.displayCart();
                break;
            case 4:
                manager.checkout();
                break;
            case 5:
                manager.displayPurchasedCourses();
                break;
            case 6:
                cout << "Logging out..." << endl;
                isLoggedIn = false;
                goto logout;
            case 7:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }

    logout:
        continue; // Go back to the login screen
    }
}