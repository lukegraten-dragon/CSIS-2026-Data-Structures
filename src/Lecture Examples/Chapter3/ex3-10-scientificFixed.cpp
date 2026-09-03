//Example: scientific and fixed
  
#include <iostream>
#include <iomanip>

using namespace std ;

int main()  
{  
    double hours = 35.45 ;
    double rate = 15.00 ;
    double tolerance = 0.01000 ;

    // On some compilers, the statements cout << fixed; and 
    // cout << scientific; might not work. In this case, 
    // you can use cout.setf(ios::fixed); in place of cout << fixed; 
    // and cout.setf(ios::scientific); in place of cout << scientific;

    cout << "hours = " << hours << ", rate = " << rate
         << ", pay = " << hours * rate
         << ", tolerance = " << tolerance << endl << endl ;

    cout << scientific << setprecision(8) ; 
    cout << "Scientific notation: " << endl ; 
    cout << "hours = " << hours << ", rate = " << rate
         << ", pay = " << hours * rate
         << ", tolerance = " << tolerance << endl << endl ;

    cout << fixed << setprecision(8) ;
    cout << "Fixed decimal notation: " << endl ;
    cout << "hours = " << hours << ", rate = " << rate
         << ", pay = " << hours * rate
         << ", tolerance = " << tolerance << endl << endl ;

    return 0 ;
}