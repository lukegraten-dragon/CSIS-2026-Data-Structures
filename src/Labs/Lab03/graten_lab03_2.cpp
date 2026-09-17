/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 03 Part 2
// Date Modified: 09-17-2026
//
/******************************************************/

# include <iostream>
using namespace std ;

int main() 
{   
    // Collect the score from input

    double score ;

    cout << "Enter the score (0-100): " ;
    cin >> score ;
    cout << endl ;

    // Assign appropriate performance message based on score:

    if (score >= 90.0)
        cout << "Excellent." << endl ;
    else if (score >= 50.0)
        cout << "Pass." << endl ; 
    else
        cout << "Fail." << endl ;

    return 0 ;
}

/******************************************************/
/*
Bugs I identified:

1) The program tracks scores within the range of 0-100
    and prints a corresponding performance message. 
    For scores less than 50.0, the conditional statement
    DOES NOT post a 'Fail.' like it should.

2) For valid scores in the passing range, they are printed
    as failing. This is because the nested if statement only
    will print excellent for values above 90. Otherwise the program
    will default to printing fail despite a score being considered
    as passing.

2.1) Assuming the grading scale of where scores equal to or above
    50 and below 90 are considered passing, the program does not
    print the 'Pass' performance message at all.

3) EXTRA: The program as-is is hard to read and while not a semantic 
    error, the sloppiness makes it more difficult to debug and
    understand the code.
*/
/******************************************************/

/*
******************************************************
Post-Lab Section Reflection

I learned that program readability has a huge impact when
it comes to debugging semantic errors in my code. Knowing what
each section does makes it easier to isolate where problems 
arise quicker.

Its also important to know and understand what conditional branches
are actually checking for to ensure they align
with the semantic design goals of the program.
******************************************************
*/