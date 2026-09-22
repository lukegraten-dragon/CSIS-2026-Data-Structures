/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Assignment 03
// Date Modified: 09-18-2026
//
/******************************************************/

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
using namespace std ;

int main () 
{
    /******************************************************/
    // Declare relevant variables 
    /******************************************************/

    string name ;
    double examScore ;
    double participation ;
    double attendance ;

    int gradeValue; // Integer that can be modified based on the grading conditions
    char letterGrade ; // Final letter grade (to be computed)
    string gradeReason ; // Optional reason why a student got their grade.

    /******************************************************/
    // Open and parse through text file if it exists.
    /******************************************************/
    ifstream inFile ;
    inFile.open("students.txt") ;  

    if (!inFile)
    {
        cout << "The correct file could not be found. Terminating program." << '\n' ;
        return 1 ;
    }

    while(inFile && !inFile.eof())
    {
        /******************************************************/
        // EOF Controlled loop and conditional logic for calculating grades
        /******************************************************/

        gradeValue = 5 ;
        inFile >> name >> examScore >> participation >> attendance ;

        // Automatic error for invalid input (attendance and/or participation)
        if ((participation < 0 || participation > 10.0) || (attendance < 0 || attendance > 10.0))
            {
                cout << name << " Error! Invalid input detected" << '\n' ;
                continue ;
            }

        // Check Attendance and decrement grade (if possible)
        if (attendance >= 5.0 && attendance <= 7.0)
            {
                gradeValue = gradeValue - 1 ;
                gradeReason = " (minus 1 letter grade due to subpar attendance)" ;
            }

        else if (attendance < 5.0)
            {
                // Failure case (no need to do extra comparison since we've guaranteed the other conditions)
                gradeValue = 0 ;
                gradeReason = " (due to low attendance)" ;
            }

        // Grading based on participation and exam scores
        if (examScore >= 90 && participation >= 7.0)
            {
                gradeValue = gradeValue - 0 ;
            }

        else if (examScore >= 80 && participation >= 6.0)
            {
                gradeValue = gradeValue - 1 ;
            }

        else if (examScore >= 70 && participation >= 5.0)
            {
                gradeValue = gradeValue - 2 ;
            }

        else if (examScore >= 60 && participation >= 4.0)
            {
                gradeValue = gradeValue - 3 ;
            }

        else
            // If participation and/or exam scores are insufficient
            {
                gradeValue = gradeValue - 4 ;
            }

        // Assign appropriate letter grade
        switch (gradeValue)
            {
                case 5:
                    letterGrade = 'A' ;
                    break ;
                case 4: 
                    letterGrade = 'B' ;
                    break ;
                case 3:
                    letterGrade = 'C' ;
                    break ;
                case 2:
                    letterGrade = 'D' ;
                    break ;
                default:
                    // Set as F if gradeValue is below 1
                    letterGrade = 'F' ;
                    break ;
            }
        /******************************************************/
        // Print appropriate output
        /******************************************************/

        cout << "Name: " << name << '\n' ;
        cout << "Grade: " << letterGrade << gradeReason << "\n\n" ;
    }
    // Close the file and terminate the program successfully
    inFile.close() ; 
    return 0 ;
}

/*
******************************************************
Post-Assigment Reflection

I discovered that an EOF loop only extracts input while extraction is successful and doesn't
 actually extract input on a per line basis like I initially thought (confused with standard stream behavior). 
 This resulted in the last line in students.txt being read twice. To fix the semantic error I introduced, I
 changed the EOF controlled loop to check if we're at the end of life, and don't execute if it is eof.

My program leveraged conditional branching (if, else if, else) to determine grading logic, file execution
 tasks, and how the EOF controlled loop operated.

The grading logic used floating point comparison to determine the base letter grade a student received via their
 participation and exam scores.
******************************************************
*/