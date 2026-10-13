#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    // Create Student object
    Student student;

    // Call class methods
    student.inputDetails();
    student.calculateAverage();
    student.displayReport();

    return 0;
}