/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Lab 02 Part 1
// Date Modified: 09-10-2026
//
/******************************************************/

# include <iostream>
using namespace std ;

int main() 
{
    // Read input via cin
    int inputInt ;
    double inputDouble ;
    char inputChar ;

    cin >> inputInt >> inputDouble >> inputChar ;

    // Output the inputted values in order (integer, double, char) via cout
    cout << "Integer: " << inputInt 
        << "\nDouble: " << inputDouble << "\nChar: " 
        << inputChar << '\n' ;
   
    return 0 ;
}

/*
Post-Lab Reflection

In this lab session I applied  cin and cout to
gather user input and print them in the order they were collected.

I assigned the collected user input to a specific data type (i.e. Int)
*/