# Online Course Management System

This repository contains the code for an **Online Course Management System** developed in **C++**. The system allows students to browse, enroll in, and purchase online courses. It showcases key Object-Oriented Programming (OOP) concepts, such as **inheritance**, **polymorphism**, and **encapsulation**.

## Project Overview

The system offers the following features for students:

- **Browse Available Courses**: Students can view details of the available courses, including the course name, price, instructor, prerequisites, and more.
- **Enroll in Courses**: Students can add courses to their cart and enroll in them.
- **Purchase Courses**: Students can proceed to checkout and purchase courses.
- **Student Login**: Students can log in using their student number and password to access personalized features and manage their account.
- **Rate Courses**: After purchasing courses, students can provide feedback by rating the course on a scale from 1 to 5.

## Key Features

### 1. **OnlineCourse (Abstract Base Class)**

The `OnlineCourse` class is the base class for all course types. It contains common properties and methods used by all courses, such as:

- **Attributes**:
  - Course name
  - Instructor
  - Difficulty level
  - Price
  - Discount rate
  - Prerequisites
- **Methods**:
  - Display course information
  - Check course availability
  - Enroll students
  - Manage course ratings

### 2. **SoftwareCourses**

The `SoftwareCourses` class inherits from `OnlineCourse` and is used to represent software-related courses such as C++, Python, and Java. Additional attributes specific to software courses include:

- Programming language
- Development environment

### 3. **MathCourses**

The `MathCourses` class inherits from `OnlineCourse` and represents math-related courses, such as Algebra, Calculus, and Statistics. It includes the following:

- Focus areas like differential and integral calculus
- Advanced mathematical concepts

### 4. **ProfessionalDevelopmentCourses**

This class, which also inherits from `OnlineCourse`, represents professional development courses. These courses focus on topics like leadership, communication skills, and team management. Additional features include:

- Certification options
- Focus on career development

### 5. **LanguageCourses**

The `LanguageCourses` class inherits from `OnlineCourse` and represents courses designed to teach languages (e.g., English for Business). It has attributes such as:

- Language being taught
- Instructor’s native language status

### 6. **Cart**

The `Cart` class manages the student's shopping cart. It allows students to:

- Add courses to the cart
- View the contents of the cart
- Proceed to checkout
- Ensure that courses are available before completing the purchase

### 7. **Student Authentication**

The system implements a basic student login system. Students can log in using their student number and password. Once logged in, they can browse, enroll in, and purchase courses.

## UML Class Diagram

The UML Class Diagram below shows how the classes are related:

- **Inheritance**: `SoftwareCourses`, `MathCourses`, `ProfessionalDevelopmentCourses`, and `LanguageCourses` inherit from `OnlineCourse`.
- **Aggregation**: The `Cart` class aggregates `OnlineCourse` objects.
- **Composition**: The `Student` class holds references to `OnlineCourse` objects representing the enrolled courses.

![Class Diagram-1](https://github.com/user-attachments/assets/b772df8e-34e6-4a23-8799-5608aa9942ef)


## Project Structure

The project consists of the following files:

- **main.cpp**: Entry point of the program where execution starts.
- **OnlineCourse.h**: Header file for the abstract `OnlineCourse` class.
- **OnlineCourse.cpp**: Implementation of the `OnlineCourse` class methods.
- **SoftwareCourses.h**: Header file for the `SoftwareCourses` class.
- **SoftwareCourses.cpp**: Implementation of the `SoftwareCourses` class methods.
- **MathCourses.h**: Header file for the `MathCourses` class.
- **MathCourses.cpp**: Implementation of the `MathCourses` class methods.
- **ProfessionalDevelopmentCourses.h**: Header file for the `ProfessionalDevelopmentCourses` class.
- **ProfessionalDevelopmentCourses.cpp**: Implementation of the `ProfessionalDevelopmentCourses` class methods.
- **LanguageCourses.h**: Header file for the `LanguageCourses` class.
- **LanguageCourses.cpp**: Implementation of the `LanguageCourses` class methods.
- **Cart.h**: Header file for the `Cart` class.
- **Cart.cpp**: Implementation of the `Cart` class methods.

## How to Run

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/OnurAkyuz61/COM3003-OOP-Project.git

2. Open the project in a C++ IDE (e.g., Visual Studio, Code::Blocks, etc.).

3. Compile and run the `main.cpp` file to start interacting with the system.


## License

This project is licensed under the MIT License. See the LICENSE file for more information.


