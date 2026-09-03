// Functions and Enumeration Types
#include <iostream>

using namespace std ;

enum courses {ALGEBRA, BASIC, PYTHON, CPP, PHILOSOPHY, ANALYSIS, CHEMISTRY, HISTORY} ;
courses registered ;

courses readCourses() ;

int main () 
{
    courses c = readCourses() ;

    cout << "registered: " << c << endl ;

    return 0 ; 
}

courses readCourses()
{
    courses registered ;

    char ch1, ch2 ;
    
    cout << "Enter the first two letters of the course: "
         << endl ;
    cin >> ch1 >> ch2 ;
    
    switch (ch1)
    {
    case 'a':
        if (ch2 == 'l')
            registered = ALGEBRA ;
        else
            registered = ANALYSIS ;
        break ;
    case 'b':
        registered = BASIC  ;
        break ;
    case 'c':
        if (ch2 == 'h')
            registered = CHEMISTRY ;
        else
            registered = CPP ;
        break ;
    case 'h':
        registered = HISTORY ;
        break ;
    case 'p':
        if (ch2 == 'y')
            registered = PYTHON ;
        else
            registered = PHILOSOPHY ;
        break ;
    default:
        cout << "Illegal input." << endl ;
    } //end switch

    return registered ;
} //end readCourse
