#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip> // For setprecision

using namespace std;

// Abstract base class
class OnlineCourse {
protected:
    string courseName, instructor, level, prerequisites;
    int totalCapacity, enrolledStudents, duration;
    double price, discountRate, totalRating;
    int ratingCount;

public:
    OnlineCourse(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration)
        : courseName(courseName), instructor(instructor), totalCapacity(totalCapacity), price(price), level(level), discountRate(discountRate), prerequisites(prerequisites), duration(duration), enrolledStudents(0), totalRating(0), ratingCount(0) {}

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
        } else {
            cout << "Invalid rating. Please enter a number between 1 and 5." << endl;
        }
    }
    virtual ~OnlineCourse() {}
};

// SoftwareCourses class
class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage, devEnvironment;

public:
    SoftwareCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string programmingLanguage, string devEnvironment)
        : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), programmingLanguage(programmingLanguage), devEnvironment(devEnvironment) {}

    void displayInfo() override {
        cout << "Software Course: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Level: " << level << endl;
        cout << "Price: ₺" << fixed << setprecision(2) << price << endl;
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

// MathCourses class
class MathCourses : public OnlineCourse {
private:
    string focusArea;

public:
    MathCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string focusArea)
        : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), focusArea(focusArea) {}

    void displayInfo() override {
        cout << "Math Course: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Level: " << level << endl;
        cout << "Price: ₺" << fixed << setprecision(2) << price << endl;
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

// ProfessionalDevelopmentCourses class
class ProfessionalDevelopmentCourses : public OnlineCourse {
private:
    bool certification;
    string topicsCovered;

public:
    ProfessionalDevelopmentCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, bool certification, string topicsCovered)
        : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), certification(certification), topicsCovered(topicsCovered) {}

    void displayInfo() override {
        cout << "Professional Development Course: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Level: " << level << endl;
        cout << "Price: ₺" << fixed << setprecision(2) << price << endl;
        cout << "Discount Rate: " << discountRate << "%" << endl;
        cout << "Prerequisites: " << prerequisites << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Certification: " << (certification ? "Yes" : "No") << endl;
        cout << "Topics Covered: " << topicsCovered << endl;
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

// LanguageCourses class
class LanguageCourses : public OnlineCourse {
private:
    string language;
    bool nativeSpeaker;

public:
    LanguageCourses(string courseName, string instructor, int totalCapacity, double price, string level, double discountRate, string prerequisites, int duration, string language, bool nativeSpeaker)
        : OnlineCourse(courseName, instructor, totalCapacity, price, level, discountRate, prerequisites, duration), language(language), nativeSpeaker(nativeSpeaker) {}

    void displayInfo() override {
        cout << "Language Course: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Level: " << level << endl;
        cout << "Price: ₺" << fixed << setprecision(2) << price << endl;
        cout << "Discount Rate: " << discountRate << "%" << endl;
        cout << "Prerequisites: " << prerequisites << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Language: " << language << endl;
        cout << "Native Speaker: " << (nativeSpeaker ? "Yes" : "No") << endl;
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

// Cart class
class Cart {
private:
    vector<OnlineCourse*> cart;
    vector<OnlineCourse*> purchasedCourses;

public:
    void addToCart(OnlineCourse* course) {
        cart.push_back(course);
        cout << course->getCourseName() << " has been added to your cart." << endl;
    }

    void displayCart() {
        if (cart.empty()) {
            cout << "Your cart is empty." << endl;
            return;
        }
        cout << "Courses in your cart:" << endl;
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << i + 1 << ". " << cart[i]->getCourseName() << " - ₺" << fixed << setprecision(2) << cart[i]->getPrice() << endl;
        }
    }

    void checkout() {
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

    void displayPurchasedCourses() {
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

// Main function
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
    vector<OnlineCourse*> availableCourses = {&programmingI, &programmingII, &oop, &calculusI, &pdCourse, &englishCourse};

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