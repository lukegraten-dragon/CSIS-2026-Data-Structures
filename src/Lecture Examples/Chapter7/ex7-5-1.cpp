// Input/Output of Enumeration Types
#include <iostream>

using namespace std ;

int main () 
{
    enum courses {ALGEBRA, BASIC, PYTHON, CPP, PHILOSOPHY, ANALYSIS, CHEMISTRY, HISTORY} ;

    courses registered ;

    char ch1, ch2 ;

    cin >> ch1 >> ch2 ;   //Read two characters

    switch (ch1)
    {
    case 'a':
        if (ch2 == 'l')
            registered = ALGEBRA ;
        else
            registered = ANALYSIS ;
        break ;
    case 'b':
        registered = BASIC ;
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
    }

    cout << "registered: " << registered << endl ;

    return 0 ; 
}