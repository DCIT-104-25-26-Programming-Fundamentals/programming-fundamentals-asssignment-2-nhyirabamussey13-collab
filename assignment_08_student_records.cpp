// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string fullName;
    int studentNumber;
    vector<double> marks;
};

void enterNewStudent(vector<Student>& records)
{
    Student temp;
    int numberOfMarks;

    cout << "Enter student's name: ";
    cin.ignore(1000, '\n');
    getline(cin, temp.fullName);

    cout << "Enter student's ID number: ";
    cin >> temp.studentNumber;

    cout << "Number of scores to enter: ";
    cin >> numberOfMarks;

    while(numberOfMarks <= 0)
    {
        cout << "Please enter at least one score: ";
        cin >> numberOfMarks;
    }

    for(int count = 0; count < numberOfMarks; count++)
    {
        double markValue;

        cout << "Score " << count + 1 << ": ";
        cin >> markValue;

        temp.marks.push_back(markValue);
    }

    records.push_back(temp);

    cout << temp.fullName << " has been added to the records.\n";
}

void showStudentRecords(const vector<Student>& records)
{
    if(records.empty())
    {
        cout << "There are currently no student records.\n";
        return;
    }

    cout << "\nStudent Records\n";
    cout << "============================\n";

    for(int i = 0; i < records.size(); i++)
    {
        double sum = 0;

        cout << "Name: " << records[i].fullName << endl;
        cout << "ID: " << records[i].studentNumber << endl;

        cout << "Scores: ";

        for(int j = 0; j < records[i].marks.size(); j++)
        {
            cout << records[i].marks[j] << " ";
            sum += records[i].marks[j];
        }

        double average = sum / records[i].marks.size();

        cout << endl;
        cout << "Average: "
             << fixed << setprecision(2)
             << average << endl;

        cout << "----------------------------\n";
    }
}

void findStudentAverage(const vector<Student>& records)
{
    int searchID;
    bool studentFound = false;

    cout << "Enter student ID to check average: ";
    cin >> searchID;

    for(int i = 0; i < records.size(); i++)
    {
        if(records[i].studentNumber == searchID)
        {
            double totalMarks = 0;

            for(int j = 0; j < records[i].marks.size(); j++)
            {
                totalMarks += records[i].marks[j];
            }

            double finalAverage = totalMarks / records[i].marks.size();

            cout << records[i].fullName
                 << "'s average is "
                 << fixed << setprecision(2)
                 << finalAverage << endl;

            studentFound = true;
            break;
        }
    }

    if(studentFound == false)
    {
        cout << "No student with that ID was found.\n";
    }
}

int main()
{
    vector<Student> studentRecords;

    Student firstStudent;
    firstStudent.fullName = "Kojo Mensah";
    firstStudent.studentNumber = 22349876;
    firstStudent.marks = {78, 85, 90};

    Student secondStudent;
    secondStudent.fullName = "Ama Owusu";
    secondStudent.studentNumber = 22345678;
    secondStudent.marks = {65, 70, 88};

    studentRecords.push_back(firstStudent);
    studentRecords.push_back(secondStudent);

    int option;

    while(true)
    {
        cout << "\n******** STUDENT RECORD MENU ********\n";
        cout << "1 - Add a student\n";
        cout << "2 - View student records\n";
        cout << "3 - Search average score\n";
        cout << "4 - Exit program\n";
        cout << "Choose an option: ";

        cin >> option;

        switch(option)
        {
            case 1:
                enterNewStudent(studentRecords);
                break;

            case 2:
                showStudentRecords(studentRecords);
                break;

            case 3:
                findStudentAverage(studentRecords);
                break;

            case 4:
                cout << "Closing student record system.\n";
                return 0;

            default:
                cout << "Please enter a valid option.\n";
        }
    }

    return 0;
}

