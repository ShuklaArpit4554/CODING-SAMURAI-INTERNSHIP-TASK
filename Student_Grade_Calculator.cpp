// User Guide:

// 1) Program Start: Run the program, and it will prompt you
// to enter the number of students whose grades you want to calculate.

// 2) Input Details: For each student, you will enter their name and ID.
// You will input their scores for assignments, quizzes, and exams. Ensure
// the scores are between 0 and 100.
// You will then enter the weightage for each category. For example,
// if assignments are 30% of the grade, enter 0.3.

// 3) Calculation: The program calculates the final grade using a 
// weighted average formula.
// It converts the numerical grade into a letter grade based on 
// standard grading scales.

// 4) Results Display: The program will display the student’s name, ID, 
// final grade, letter grade, and additional comments or feedback based on 
// their performance.

// 5) Multiple Students: The program will repeat the process for each student 
// until all students' grades have been entered and calculated.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold student information
struct Student {
    string name;       // Student's name
    int id;            // Student's ID number
    double assignments; // Score for assignments
    double quizzes;     // Score for quizzes
    double exams;       // Score for exams
    double finalGrade;  // Final calculated grade
    char letterGrade;   // Letter grade based on finalGrade
    string comments;    // Comments based on the letterGrade
};

// Function to determine the letter grade based on the final grade
char calculateLetterGrade(double grade) {
    if (grade >= 90) return 'A';   // Grade A for 90 and above
    else if (grade >= 80) return 'B'; // Grade B for 80 and above
    else if (grade >= 70) return 'C'; // Grade C for 70 and above
    else if (grade >= 60) return 'D'; // Grade D for 60 and above
    else return 'F';                 // Grade F for below 60
}

// Function to generate comments based on the letter grade
string generateComments(char letterGrade) {
    switch (letterGrade) {
        case 'A': return "Excellent work!";   // Comments for grade A
        case 'B': return "Good job!";         // Comments for grade B
        case 'C': return "Satisfactory performance."; // Comments for grade C
        case 'D': return "Needs improvement."; // Comments for grade D
        default: return "Poor performance.";  // Comments for grade F
    }
}

// Function to calculate the final grade based on scores and weightage
double calculateFinalGrade(double assignments, double quizzes, double exams, double assignmentWeight, double quizWeight, double examWeight) {
    return (assignments * assignmentWeight + quizzes * quizWeight + exams * examWeight) / 100;
}

int main() {
    vector<Student> students;    // Vector to store multiple students' information
    char continueInput = 'y';    // Variable to control whether to continue inputting students
    double assignmentWeight, quizWeight, examWeight;  // Weightage for each category

    // Input the weightage percentages for assignments, quizzes, and exams
    cout << "Enter weightage for Assignments (%): ";
    cin >> assignmentWeight;
    cout << "Enter weightage for Quizzes (%): ";
    cin >> quizWeight;
    cout << "Enter weightage for Exams (%): ";
    cin >> examWeight;

    // Loop to enter information for each student
    while (continueInput == 'y') {
        Student student;  // Create a new student instance

        // Input student's name and ID
        cout << "Enter student name: ";
        cin >> student.name;
        cout << "Enter student ID: ";
        cin >> student.id;

        // Input and validate assignment score
        do {
            cout << "Enter assignment score (0-100): ";
            cin >> student.assignments;
        } while (student.assignments < 0 || student.assignments > 100);

        // Input and validate quiz score
        do {
            cout << "Enter quiz score (0-100): ";
            cin >> student.quizzes;
        } while (student.quizzes < 0 || student.quizzes > 100);

        // Input and validate exam score
        do {
            cout << "Enter exam score (0-100): ";
            cin >> student.exams;
        } while (student.exams < 0 || student.exams > 100);

        // Calculate the final grade and determine the letter grade and comments
        student.finalGrade = calculateFinalGrade(student.assignments, student.quizzes, student.exams, assignmentWeight, quizWeight, examWeight);
        student.letterGrade = calculateLetterGrade(student.finalGrade);
        student.comments = generateComments(student.letterGrade);

        // Add the student to the vector of students
        students.push_back(student);

        // Ask if the user wants to enter another student
        cout << "Do you want to enter another student? (y/n): ";
        cin >> continueInput;
    }

    // Display the grade report for each student
    for (const auto& student : students) {
        cout << "\nStudent Name: " << student.name
             << "\nStudent ID: " << student.id
             << "\nFinal Grade: " << student.finalGrade
             << "\nLetter Grade: " << student.letterGrade
             << "\nComments: " << student.comments << endl;
    }

    return 0;
}
