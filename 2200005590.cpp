#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip> // For setprecision

using namespace std;

// Abstract base class for all courses
class OnlineCourse {
protected:
    string courseName, instructor, level, prerequisites;
    int totalCapacity, enrolledStudents, duration;
    double price, discountRate, totalRating;
    int ratingCount;

public:
    OnlineCourse(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur) : courseName(name), instructor(instr), totalCapacity(capacity), price(pr), level(lvl), discountRate(discRate), prerequisites(prereq), duration(dur), enrolledStudents(0), totalRating(0), ratingCount(0) {}

    virtual void displayInfo() = 0;
    virtual bool addStudent() = 0;
    virtual bool checkCapacity() = 0;

    double getPrice() const {
        return price;
    }

    double getDiscountRate() const {
        return discountRate;
    }

    string getCourseName() const {
        return courseName;
    }

    double getAverageRating() const {
        return ratingCount > 0 ? totalRating / ratingCount : 0.0;
    }

    void rateCourse(int rating) {
        if (rating >= 1 && rating <= 5) {
            totalRating += rating;
            ratingCount++;
            cout << "Thank you for rating the course!" << endl;
        }
        else {
            cout << "Invalid rating. Please enter a number between 1 and 5." << endl;
        }
    }

    virtual ~OnlineCourse() {}
};

// Derived class for Software Courses
class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage, devEnvironment;

public:
    SoftwareCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, int dur, string lang, string devEnv) : OnlineCourse(name, instr, capacity, pr, lvl, discRate, prereq, dur), programmingLanguage(lang), devEnvironment(devEnv) {}

    void displayInfo() override {
        cout << "Software Course: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Level: " << level << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
        cout << "Discount Rate: " << discountRate << "%" << endl;
        cout << "Prerequisites: " << prerequisites << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
        cout << "Development Environment: " << devEnvironment << endl;
        cout << "Average Rating: " << fixed << setprecision(2) << getAverageRating() << " / 5" << endl;
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

// Derived class for Math Courses
class MathCourses : public OnlineCourse {
private:
    string focusArea;

public:
    MathCourses(string name, string instr, int capacity, double pr, string lvl, double discRate,
        string prereq, int dur, string area)
        : OnlineCourse(name, instr, capacity, pr, lvl, discRate, prereq, dur), focusArea(area) {}

    void displayInfo() override {
        cout << "Math Course: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Level: " << level << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
        cout << "Discount Rate: " << discountRate << "%" << endl;
        cout << "Prerequisites: " << prerequisites << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Focus Area: " << focusArea << endl;
        cout << "Average Rating: " << fixed << setprecision(2) << getAverageRating() << " / 5" << endl;
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

// Discount calculation function
double calculateDiscountedPrice(OnlineCourse* course) {
    return course->getPrice() * (1 - course->getDiscountRate() / 100.0);
}

// Class to manage student and cart
class Cart {
private:
    vector<OnlineCourse*> cart;
    vector<OnlineCourse*> purchasedCourses;

public:
    void addToCart(OnlineCourse* course) {
        // Sepette aynı kurs olup olmadığını kontrol et
        for (OnlineCourse* c : cart) {
            if (c->getCourseName() == course->getCourseName()) {
                cout << "This course is already in your cart." << endl;
                return;
            }
        }
        // Kapasiteyi kontrol et
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
        double total = 0;
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << i + 1 << ". ";
            cart[i]->displayInfo();
            double discountedPrice = calculateDiscountedPrice(cart[i]);
            cout << "Original Price: $" << fixed << setprecision(2) << cart[i]->getPrice() << endl;
            cout << "Discounted Price: $" << discountedPrice << endl;
            total += discountedPrice;
        }
        cout << "Total Price: $" << total << endl;
    }

    void checkout() {
        if (cart.empty()) {
            cout << "Cart is empty. Nothing to purchase." << endl;
            return;
        }

        double total = 0;
        for (OnlineCourse* course : cart) {
            total += calculateDiscountedPrice(course);
        }

        cout << "Total Price: $" << total << endl;
        cout << "Enter your card details to complete the payment:" << endl;

        string cardName, cardNumber, cvv;
        cout << "Card Holder Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, cardName);
        cout << "Card Number: ";
        cin >> cardNumber;
        cout << "CVV: ";
        cin >> cvv;

        cout << "Processing payment..." << endl;
        cout << "Payment successful! Thank you for your purchase." << endl;

        for (OnlineCourse* course : cart) {
            purchasedCourses.push_back(course);
            course->addStudent();
        }
        cart.clear();
    }

    void displayPurchasedCourses() {
        if (purchasedCourses.empty()) {
            cout << "You have not purchased any courses." << endl;
            return;
        }
        cout << "Purchased Courses:" << endl;
        for (size_t i = 0; i < purchasedCourses.size(); ++i) {
            purchasedCourses[i]->displayInfo();
            cout << "Would you like to rate this course? (1-5): ";
            int rating;
            cin >> rating;
            purchasedCourses[i]->rateCourse(rating);
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
    cout << "**********************************************" << endl;
    cout << "* Welcome to the Online Course Management!  *" << endl;
    cout << "**********************************************" << endl << endl;

    map<string, string> studentDatabase = {
        {"2200005590", "onur"},
        {"2200005798", "esma"},
        {"2300008096", "melisa"}
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
                loggedIn = false;
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