/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Assignment 02
// Date Modified: 09-15-2026
//
/******************************************************/

# include <iostream>
# include <iomanip>
# include <string>
using namespace std ;

int main ()
{   
    string headerLine = "------------------------------------------------------------" ;
    int columnWidth = 15 ;

    /******************************************************/
    // Ask for user input
    /******************************************************/
    double input1 ;
    double input2 ;
    double input3 ;
    double input4 ;
    double input5 ;

    cout << "Enter five floating-point numbers: " ;

    cin >> input1 
        >> input2
        >> input3
        >> input4
        >> input5 ;

    cout << '\n' ;

    /******************************************************/
    // Print header and title line
    /******************************************************/

    cout << headerLine << '\n' ;

    cout << setw(columnWidth) << "Original"
        << setw(columnWidth) << "Rounded"
        << setw(columnWidth) << "Fixed Point"
        << setw(columnWidth) << "Scientific"
        << '\n' ;

    cout << headerLine << '\n' ;

    /******************************************************/
    // Format display output
    /******************************************************/

    cout << setprecision(10)
         << setw(columnWidth) << input1 // Original value up to 10 sig figs
         << setw(columnWidth) << round(input1) // Rounded
         << setw(columnWidth) << fixed << showpoint << setprecision(3) << input1 // Fixed Decimal
         << setw(columnWidth) << scientific << input1 // Scientific
         << '\n';
    
    cout.unsetf(ios::fixed) ; // Unset format manipulators
    cout.unsetf(ios::showpoint) ;
    cout.unsetf(ios::scientific) ;

    cout << setprecision(10)
         << setw(columnWidth) << input2
         << setw(columnWidth) << round(input2)
         << setw(columnWidth) << fixed << showpoint << setprecision(3) << input2
         << setw(columnWidth) << scientific << input2 
         << '\n'; 

    cout.unsetf(ios::fixed) ; 
    cout.unsetf(ios::showpoint) ;
    cout.unsetf(ios::scientific) ;

    cout << setprecision(10)
         << setw(columnWidth) << input3
         << setw(columnWidth) << round(input3)
         << setw(columnWidth) << fixed << showpoint << setprecision(3) << input3
         << setw(columnWidth) << scientific << input3
         << '\n'; 

    cout.unsetf(ios::fixed) ; 
    cout.unsetf(ios::showpoint) ;
    cout.unsetf(ios::scientific) ;

    cout << setprecision(10)
         << setw(columnWidth) << input4
         << setw(columnWidth) << round(input4)
         << setw(columnWidth) << fixed << showpoint << setprecision(3) << input4
         << setw(columnWidth) << scientific << input4
         << '\n';

    cout.unsetf(ios::fixed) ; 
    cout.unsetf(ios::showpoint) ;
    cout.unsetf(ios::scientific) ;

    cout << setprecision(10)
         << setw(columnWidth) << input5
         << setw(columnWidth) << round(input5)
         << setw(columnWidth) << fixed << showpoint << setprecision(3) << input5
         << setw(columnWidth) << scientific << input5
         << '\n'; 
    
    return 0 ;
}

/*
******************************************************
Post-Assigment Reflection

This assigment and the lecture exercises Dr. Lee showed the class on Monday greatly
helped improve my understanding of formatting manipulators. Compared to Lab02
I have a much clearer idea of how each manipulator works.

Using this knowledge I can create more consistent looking and nicely formatted
output when displaying data in the terminal.

Overall this program worked as intended per the reference example. Although
I already know that loops exist, repeating entire blocks of code seemed nasty
and reminds me that less code is easier to read and maintain (if I need to make corrections).
******************************************************
*/