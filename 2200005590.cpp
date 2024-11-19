#include <iostream> // Include standard input-output stream library

using namespace std; // Use the standard namespace

// Base class for all online courses
class OnlineCourse {
protected:
    string courseName; // Course name
    string instructor; // Instructor's name
    int totalCapacity; // Total capacity of the course
    int enrolledStudents; // Number of students enrolled
    double courseRate; // Course rating
    int duration; // Course duration in hours
    double price; // Course price
    string level; // Course level (e.g., Beginner, Intermediate)
    double discountRate; // Discount rate for the course
    string prerequisites; // Prerequisites for the course

public:
    void displayInfo(); // Displays course information
    bool addStudent(); // Adds a student to the course
    bool checkCapacity(); // Checks if there is available capacity
    ~OnlineCourse(); // Destructor
};

// Derived class for software-related courses
class SoftwareCourses : public OnlineCourse {
private:
    string programmingLanguage; // Programming language used in the course
    string devEnvironment; // Development environment for the course

public:
    void displayInfo(); // Displays software course information
    bool addStudent(); // Adds a student to the software course
    bool checkCapacity(); // Checks capacity for the software course
    SoftwareCourses();

    void displayInfo() {
        cout << "Software Course Name: " << courseName << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
        cout << "Development Environment: " << devEnvironment << endl;
        cout << "Total Capacity: " << totalCapacity << endl;
        cout << "Enrolled Students: " << enrolledStudents << endl;
        cout << "Price: $" << price << endl;
        cout << "Discount Rate: " << discountRate << "%" << endl;
        cout << "Level: " << level << endl;
        cout << "Prerequisites: " << prerequisites << endl;
    }

    bool addStudent() {
        if (checkCapacity()) {
            enrolledStudents++;
            cout << "Student successfully added to the software course." << endl;
            return true;
        }
        cout << "No available capacity for this course." << endl;
        return false;
    }

    bool checkCapacity() {
        return enrolledStudents < totalCapacity;
    }

    SoftwareCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, string lang, string devEnv) {
        courseName = name;
        instructor = instr;
        totalCapacity = capacity;
        enrolledStudents = 0;
        price = pr;
        level = lvl;
        discountRate = discRate;
        prerequisites = prereq;
        programmingLanguage = lang;
        devEnvironment = devEnv;
    }
};

// Derived class for language-related courses
class LanguageCourses : public OnlineCourse {
private:
    string language; // Language being taught
    bool isNativeSpeaker; // Indicates if the instructor is a native speaker

public:
    LanguageCourses(); // Constructor for LanguageCourses
    void displayInfo(); // Displays language course information
    bool addStudent(); // Adds a student to the language course
    bool checkCapacity(); // Checks capacity for the language course

    void displayInfo() {
        OnlineCourse::displayInfo();
        cout << "Language: " << language << endl;
        cout << "Native Speaker: " << (isNativeSpeaker ? "Yes" : "No") << endl;
    }

    LanguageCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, string lang, bool isNative) {
        courseName = name;
        instructor = instr;
        totalCapacity = capacity;
        enrolledStudents = 0;
        price = pr;
        level = lvl;
        discountRate = discRate;
        prerequisites = prereq;
        language = lang;
        isNativeSpeaker = isNative;
    }
};

// Derived class for professional development courses
class ProfessionalDevelopmentCourses : public OnlineCourse {
private:
    bool providesCertification; // Indicates if the course provides certification
    string topics; // Topics covered in the course

public:
    ProfessionalDevelopmentCourses(); // Constructor for ProfessionalDevelopmentCourses
    void displayInfo(); // Displays professional development course info
    bool addStudent(); // Adds a student to the professional development course
    bool checkCapacity(); // Checks capacity for the professional development course

    ProfessionalDevelopmentCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, bool cert, string topicsCovered) {
        courseName = name;
        instructor = instr;
        totalCapacity = capacity;
        enrolledStudents = 0;
        price = pr;
        level = lvl;
        discountRate = discRate;
        prerequisites = prereq;
        providesCertification = cert;
        topics = topicsCovered;
    }
};

// Extra course type: Art-related courses
class ArtCourses : public OnlineCourse {
private:
    string artType; // Type of art taught in the course (e.g., Painting)
    bool materialsIncluded; // Indicates if materials are included in the course

public:
    ArtCourses(); // Constructor for ArtCourses
    void displayInfo(); // Displays art course information
    bool addStudent(); // Adds a student to the art course
    bool checkCapacity(); // Checks capacity for the art course

    void displayInfo() {
        OnlineCourse::displayInfo();
        cout << "Art Type: " << artType << endl;
        cout << "Materials Included: " << (materialsIncluded ? "Yes" : "No") << endl;
    }

    ArtCourses(string name, string instr, int capacity, double pr, string lvl, double discRate, string prereq, string art, bool materialsInc) {
        courseName = name;
        instructor = instr;
        totalCapacity = capacity;
        enrolledStudents = 0;
        price = pr;
        level = lvl;
        discountRate = discRate;
        prerequisites = prereq;
        artType = art;
        materialsIncluded = materialsInc;
    }
};

// Student class for managing student information and enrolled courses
class Student {
private:
    string name; // Student's name
    string surname; // Student's surname
    string email; // Student's email address
    OnlineCourse* enrolledCourses; // Array of courses the student is enrolled in

public:
    Student(string name, string surname, string email) {} // Constructor for Student
    void enrollCourse(OnlineCourse* course); // Enroll student in a course
    void viewEnrolledCourses(); // View courses student is enrolled in
    void rateCourse(OnlineCourse* course, double rating); // Rate a course
};

// Cart class for managing courses selected for purchase
class Cart {
private:
    OnlineCourse* selectedCourses; // Array of courses selected in the cart

public:
    void addCourse(OnlineCourse* course); // Add course to the cart
    void removeCourse(OnlineCourse* course); // Remove course from the cart
    void confirmCart(); // Confirm courses in the cart
    void viewCart(); // View courses in the cart
};

// Function to calculate discounted price of any course
double calculateDiscountedPrice(const OnlineCourse& course) {
    //return course.price * (1 - course.discountRate / 100.0); // Calculate and return discounted price
}

int main() {
    // Example instances of different course types
    SoftwareCourses cppCourse("Advanced C++ Programming", "Alice Johnson", 20, 149.99, "Intermediate", 10.0, "Basic C++ Knowledge", "C++", "Visual Studio");
    LanguageCourses spanishCourse("Spanish for Beginners", "Maria Lopez", 15, 99.99, "Beginner", 15.0, "None", "Spanish", true);
    ArtCourses paintingCourse("Watercolor Techniques", "John Smith", 10, 79.99, "Beginner", 20.0, "Basic Art Supplies", "Painting", true);

    // Display information for each course
    cout << "Software Course Info:\n";
    cppCourse.displayInfo();
    cout << "\nLanguage Course Info:\n";
    spanishCourse.displayInfo();
    cout << "\nArt Course Info:\n";
    paintingCourse.displayInfo();

    return 0; // Main function entry point
}