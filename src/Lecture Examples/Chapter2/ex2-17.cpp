// This program illustrates how input statements work.
  
#include <iostream>

using namespace std ;

int main()  
{
    // int feet ;
    // int inches ;
    double feet ;
    double inches ;

    cout << "Enter two integers separated by one or more spaces: " ;

    // cin uses >> notation to represent getting input from the user. 
    cin >> feet >> inches ;
    cout << endl ;

    cout << "Feet = " << feet << endl ;
    cout << "Inches = " << inches << endl ;
    
    return 0 ;
}