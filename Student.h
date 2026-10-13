
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    // Data members
    int studentID;
    string name;
    double english;
    double mathematics;
    double science;
    double average;

public:
    // Constructor
    Student();

    // Method declarations
    void inputDetails();
    double inputGrade(string subject);
    void calculateAverage();
    string getRemarks() const;
    void displayReport() const;
};

#endif
