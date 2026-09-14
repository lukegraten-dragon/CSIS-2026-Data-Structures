/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Couse: CSIS 255
// Lab 02 Part 4
// Date Modified: 09-10-2026
//
/******************************************************/

# include <iostream>
# include <iomanip>
# include <string>
using namespace std ;

int main ()
{
    // Formatting stuff
    string lineDiv = "------------------------------------------------------" ;
    int columnWidth = 20 ;

    // Ask for user input
    double input1 ;
    double input2 ;
    double input3 ;

    cout << "Enter three double numbers: " ;
    cin >> input1 >> input2 >> input3 ;
    cout << '\n' ;

    // Print Header
    cout << left;
    cout << "\n"
        << lineDiv
        << "\n"
        << setw(columnWidth)
        << "Original" << setw(columnWidth)
        << "Fixed Point" << setw(columnWidth)
        << "Scientific"
        << "\n"
        << lineDiv
        << '\n' ;

    // Display results
    // NOTE: After each input cycle, the places shown is set to
    // to a precision level of up to 6 places after the decimal. Since
    // the setprecision() formatting function used in previous input is sticky
    // and persistent unless 'toggled off' using unsetf(), (which
    // the instructions of this lab doesn't specify). Even though
    // the stored value isn't changed internally when formatting is applied.

    cout << setw(columnWidth) <<input1
        << fixed << setprecision(3) << setw(columnWidth) << input1
        << scientific << setw(columnWidth) << input1
        << fixed << setprecision(6)
        << '\n' ;


    cout << setw(columnWidth) << input2
        << setprecision(3) << setw(columnWidth) << input2
        << scientific << setw(columnWidth) << input2
        << fixed << setprecision(6)
        << '\n' ;

    cout << setw(columnWidth) << input3
        << setprecision(3) << setw(columnWidth) << input3
        << scientific << setw(columnWidth) << input3
        << '\n' ;

    cout << lineDiv
        << '\n' ;

    return 0 ;
}

/*
Post-Lab Reflection

I found that this exercise was more challenging to complete
compared to the others due to the constraints imposed by the exercise instructions.

Since the input can accept any length of double value, the spacing between values (columns)
couldn't automatically adapt to look consistent for larger values, which shows me the limits of using
setw() to format my data.
*/