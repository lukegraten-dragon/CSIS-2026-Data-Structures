// Switch Statement

#include <iostream>

using namespace std ;

int main()
{
    char grade ;

    cout << "Enter a grade: " ;
    cin >> grade ;
    cout << endl ;

    switch (grade)
    {
    case 'A':
        cout << "The grade point is 4.0." ;
        break ;
    case 'B':
        cout << "The grade point is 3.0." ;
        break ;
    case 'C':
        cout << "The grade point is 2.0." ;
        break ;
    case 'D':
        cout << "The grade point is 1.0." ;
        break ;
    case 'F':
        cout << "The grade point is 0.0." ;
        break ;
    default:
        cout << "The grade is invalid." ;
    }

    cout << endl ;
    
    return 0 ;
} 