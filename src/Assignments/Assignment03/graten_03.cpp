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
# include <cmath>
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

    int gradeValue = 5 ; // Integer that can be modified based on the conditions
    char letterGrade ; // Final letter grade (to be computed)
    string gradeReason ; // Optional reason why a student got their grade.

    
    /******************************************************/
    // Parse through txt file
    /******************************************************/

    cout << "Input sample data (test only): " ;
    cin >> name >> examScore >> participation >> attendance ;
    cout << '\n' ;

    /******************************************************/
    // Conditional logic for calculating grades
    /******************************************************/

    // Automatic error for invalid scores (Convert to assert or something similar and skip the current loop iteration)
    if (participation < 0 || participation > 10.0)
        {
            cout << "Error! Invalid Participation Value" << '\n' ;
        }

    if (attendance < 0 || attendance > 10.0)
        {
            cout << "Error! Invalid Attendance Value" << '\n' ;
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
        gradeValue = gradeValue - 0 ;

    else if (examScore >= 80 && participation >= 6.0)
        gradeValue = gradeValue - 1 ;

    else if (examScore >= 70 && participation >= 5.0)
        gradeValue = gradeValue - 2 ;

    else if (examScore >= 60 && participation >= 4.0)
        gradeValue = gradeValue - 3 ;

    else
        // If participation and exam scores are insufficient
        gradeValue = gradeValue - 4 ;

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
                // Set as F is gradeValue is below 1
                letterGrade = 'F' ;
                break ;
        }

    /******************************************************/
    // Print appropriate output
    /******************************************************/

    cout << "Name: " << name << '\n' ;
    cout << "Grade: " << letterGrade << gradeReason << '\n' ;

    return 0 ;
}

/*
******************************************************
Post-Assigment Reflection

******************************************************
*/