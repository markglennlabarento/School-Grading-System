
#include "Student.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
using namespace std;

// Constructor
Student::Student()
    : studentID(0), name(""), english(0.0), mathematics(0.0), science(0.0), average(0.0) {
}

// Input student information
void Student::inputDetails() {
    cout << "Enter student ID: ";
    cin >> studentID;

    cout << "Enter student name: ";
    getline(cin >> ws, name);

    english = inputGrade("English");
    mathematics = inputGrade("Mathematics");
    science = inputGrade("Science");
}

// Validate and return grade
double Student::inputGrade(string subject) {
    double grade;
    while (true) {
        cout << "Enter " << subject << " grade (0-100): ";
        if (cin >> grade) {
            if (grade >= 0.0 && grade <= 100.0) {
                return grade;
            }
        } else {
            if (cin.eof()) {
                throw ios_base::failure("Input ended before a valid grade was entered.");
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Invalid grade. Enter a number between 0 and 100.\n";
    }
}

// Calculate average
void Student::calculateAverage() {
    cout << "\nCalculating average...\n";
    average = (english + mathematics + science) / 3.0;
}

// Determine pass or fail
string Student::getRemarks() const {
    return average >= 75.0 ? "Passed" : "Failed";
}

// Display report card
void Student::displayReport() const {
    cout << "\nDisplaying report card...\n"
         << "========== STUDENT REPORT CARD ==========\n"
         << "Student ID: " << studentID << '\n'
         << "Name: " << name << '\n'
         << fixed << setprecision(2)
         << "English: " << english << '\n'
         << "Mathematics: " << mathematics << '\n'
         << "Science: " << science << '\n'
         << "Average: " << average << '\n'
         << "Remarks: " << getRemarks() << '\n'
         << "=========================================\n";
}
