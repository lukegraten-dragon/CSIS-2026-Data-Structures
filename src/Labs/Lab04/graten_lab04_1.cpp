/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 04 Part 1
// Date Modified: 09-24-2026
//
/******************************************************/

# include <iostream>
# include <string>

using namespace std ;

string day_finder(int dayInteger)
{
    string derivedDayName ;

    // Use a switch statement to derive the correct day
    switch (dayInteger)
    {
        case 1:
            derivedDayName = "Monday" ;
            break ;
        case 2:
            derivedDayName = "Tuesday" ;
            break ;
        case 3:
            derivedDayName = "Wednesday" ;
            break ;
        case 4:
            derivedDayName = "Thursday" ;
            break ;
        case 5:
            derivedDayName = "Friday" ;
            break ;
        case 6:
            derivedDayName = "Saturday" ;
            break ;
        case 7: 
            derivedDayName = "Sunday" ;
            break ;
        default:
            derivedDayName = "Undefined" ;
            break ;
    }

    return derivedDayName ;
}

/******************************************************/
// BEGIN MAIN HERE
/******************************************************/

int main () {
    // Initialize variables
    int dayInt = -999 ; // placeholder value to avoid compile warning
    string dayName ;

    // User input loop
    while (!(dayInt >= 1 && dayInt <= 7)) 
    {   
        cout << "Enter a number between 1 and 7 to represent a day of the week: " ;
        cin >> dayInt ;
        cout << '\n' ;

        if (!(dayInt >= 1 && dayInt <= 7))
        {
            cout << "Invalid input, please enter a number between 1 and 7." << '\n' ;
        }

        // Remove and clear invalid input such as a char
        cin.clear() ;
        cin.ignore(100, '\n') ;
    }

    // Use day_finder to return the dayInt as a string
    cout << "It's " << day_finder(dayInt) << "! \n" ;

    return 0 ;
}

/*
Post Lab Reflection:

In this lab I used a switch statement to comopare the user input against
a valid range of values that could be assigned a day string value (1 -> "Monday").

To apply recent learnings in the class. I assigned the day finding functionality
to a dedicated function. Which helps avoid repeating myself (DRY) if
the program were to be modified in the future to accept 2 dayIntegers or the like.

I also wanted to ensure that no one could place an invalid type
such as a char in the input. So I used a while loop that
executed as long as dayInt wasn't in the valid range and clear the 
stream if a bad input was inserted.
*/