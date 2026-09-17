/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 03 Part 1
// Date Modified: 09-17-2026
//
/******************************************************/

# include <iostream>
# include <iomanip>
using namespace std ;

int main()
{
    double assignmentWork ;
    double midtermExam ;
    double finalExam ;
    double finalPercentage ;
    char letterGrade ;

    const double assignmentWeight = 0.4 ;
    const double midtermWeight = 0.25 ;
    const double finalWeight = 0.35 ;

    /******************************************************/
    // Store categorical variables
    /******************************************************/

    cout << "Enter the assignment score (0-100): " ;
    cin >> assignmentWork ;

    cout << "Enter the midterm exam score (0-100): " ;
    cin >> midtermExam ;

    cout << "Enter the final exam score (0-100): " ;
    cin >> finalExam ;

    /******************************************************/
    // Compute the weighted score of all 3 categories
    /******************************************************/

    finalPercentage = (assignmentWork * assignmentWeight) +
        (midtermExam * midtermWeight) +
        (finalExam * finalWeight) ;

    /******************************************************/
    // Determine the letter grade via conditional branching.
    /******************************************************/

    if (finalPercentage > 90.00)
        letterGrade = 'A' ;
    else if (finalPercentage > 80.00)
        letterGrade = 'B' ;
    else if (finalPercentage > 70.00)
        letterGrade = 'C' ;
    else if (finalPercentage > 60.00)
        letterGrade = 'D' ;
    else
        // Depends on institution, but by default student gets F :(
        letterGrade = 'F' ;

    /******************************************************/
    // Display the final percentage and corresponding letter grade.
    /******************************************************/

    cout << fixed << showpoint << setprecision(2) ;
    cout << "\nFinal Percentage: " << finalPercentage << "%" << '\n' ;
    cout << "Letter Grade: " << letterGrade << '\n' ;

    return 0 ;
}

/*
******************************************************
Post-Lab Section Reflection

I felt that this lab exercise made me understand if else statements
and conditional branching more thoroughly. 

It also helped reinforce my understanding of previous concepts, 
such as constant, cout, cin, and formatting manipulators.
******************************************************
*/