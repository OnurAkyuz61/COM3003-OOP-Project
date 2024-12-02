#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Abstract base class for all courses
class OnlineCourse {
protected:
    string courseName, instructor, level, prerequisites;
    int totalCapacity, enrolledStudents, duration;
    double price, discountRate;

public:
    OnlineCourse(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur) : courseName(name), instructor(instr), totalCapacity(capacity), price(pr), level(lvl), discountRate(discRate), prerequisites(prereq), duration(dur), enrolledStudents(0) {}

    virtual void displayInfo() = 0;
    virtual bool addStudent() = 0;
    virtual bool checkCapacity() = 0;

    double getPrice() const {
        return price;
    }

    double getDiscountRate() const {
        return discountRate;
    }

    virtual ~OnlineCourse() {}
};

// Derived class for Software Courses
class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage, devEnvironment;

public:
    SoftwareCourses(string name, string instr, int capacity, double pr, string lvl, double discRate,
        string prereq, int dur, string lang, string devEnv)
        : OnlineCourse(name, instr, capacity, pr, lvl, discRate, prereq, dur),
        programmingLanguage(lang), devEnvironment(devEnv) {}

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

// Class to manage student and cart
class Cart {
private:
    vector<OnlineCourse*> cart;
    vector<OnlineCourse*> purchasedCourses;

public:
    void addToCart(OnlineCourse* course) {
        if (course->checkCapacity()) {
            cart.push_back(course);
            cout << "Course added to cart." << endl;
        }
        else {
            cout << "Course is full and cannot be added." << endl;
        }
    }

    void displayCart() {
        if (cart.empty()) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "Courses in your cart:" << endl;
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << i + 1 << ". ";
            cart[i]->displayInfo();
        }
    }

    void checkout() {
        if (cart.empty()) {
            cout << "Cart is empty. Nothing to purchase." << endl;
            return;
        }
        cout << "Processing payment..." << endl;
        for (OnlineCourse* course : cart) {
            purchasedCourses.push_back(course);
            course->addStudent();
        }
        cart.clear();
        cout << "Purchase successful! Courses have been added to your purchased list." << endl;
    }

    void displayPurchasedCourses() {
        if (purchasedCourses.empty()) {
            cout << "You have not purchased any courses." << endl;
            return;
        }
        cout << "Purchased Courses:" << endl;
        for (OnlineCourse* course : purchasedCourses) {
            course->displayInfo();
        }
    }
};

// Login function
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
    // Welcome message
    cout << "**********************************************" << endl;
    cout << "* Welcome to the Online Course Management!  *" << endl;
    cout << "**********************************************" << endl << endl;

    // Student database
    map<string, string> studentDatabase = {
        {"2200005590", "password123"},
        {"2200005591", "securepass"},
        {"2200005592", "mypassword"}
    };

    // Courses
    SoftwareCourses cppCourse("Advanced C++ Programming", "Alice Johnson", 20, 149.99, "Intermediate", 10.0, "Basic C++ Knowledge", 40, "C++", "Visual Studio");
    SoftwareCourses pythonCourse("Python for Data Science", "John Smith", 25, 129.99, "Beginner", 15.0, "None", 35, "Python", "Jupyter Notebook");

    vector<OnlineCourse*> availableCourses = {
        &cppCourse, &pythonCourse };

    Cart cart;

    while (true) { // Outer loop for logout functionality
        bool loggedIn = false;

        while (!loggedIn) {
            loggedIn = login(studentDatabase);
        }

        // Main menu
        while (loggedIn) {
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
                cout << "Logging out..." << endl;
                loggedIn = false; // Exit the inner loop
                break;

            case 7:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    return 0;
}