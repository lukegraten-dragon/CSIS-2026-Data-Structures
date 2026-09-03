#include <iostream>

using namespace std ;

int main () 
{
    // double balance ;
    double balance = 60000 ;
    double interestRate ;

    if (balance > 50000.00)           //Line 1
        interestRate = 0.07 ;         //Line 2
    else                              //Line 3
        if (balance >= 25000.00)      //Line 4
            interestRate = 0.05 ;     //Line 5
        else                          //Line 6
            if (balance >= 1000.00)   //Line 7
                interestRate = 0.03 ; //Line 8
            else                      //Line 9
                interestRate = 0.00 ; //Line 10

    // if (balance > 50000.00)           //Line 1
    //     interestRate = 0.07 ;         //Line 2
    // else if (balance >= 25000.00)     //Line 3
    //     interestRate = 0.05 ;         //Line 4
    // else if (balance >= 1000.00)      //Line 5
    //     interestRate = 0.03 ;         //Line 6
    // else                              //Line 7
    //     interestRate = 0.00 ;         //Line 8

    cout << "interestRate = " << interestRate << endl ;
    return 0 ;
}