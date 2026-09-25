/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 04 Part 3
// Date Modified: 09-25-2026
//
/******************************************************/

# include <iostream>
# include <array>
using namespace std ;

int num_compare(int numOne, int numTwo)
{
    // Compare two numbers and return smallest
    if (numOne < numTwo)
    {   
        // Return first number to be compared
        return numOne ;
    } 
    else
    {
        // Covers both cases where numTwo is less than numOne and if
        // they are equal, just return either.
        return numTwo ;
    }
}

/******************************************************/
// BEGIN MAIN HERE
/******************************************************/

int main ()
{   
    int smallestNum ; // Smallest num to be decied
    
    // 10 Variables for input
    int intOne ;
    int intTwo ;
    int intThree ;
    int intFour ;
    int intFive ;
    int intSix ;
    int intSeven ;
    int intEight ;
    int intNine ;
    int intTen ;

    // Ask for user input
    // SAMPLE: 15 23 6 9 11 45 1 3 8 17
    cout << "Enter 10 numbers: " ;
    cin >> intOne >> intTwo >> intThree >> intFour >> intFive
        >> intSix >> intSeven >> intEight >> intNine >> intTen ;
    cout << '\n' ;

    // Give smallestNum a value within the inputted value "list"
    smallestNum = intFive ;

    // Use num_compare to find smallest number
    for (int i = 0 ; i < 10; i++)
    {
        // Do per iteration comparison, reassign smallestNum when int<Number> is less than smallestNum
        switch (i)
        {
            case 0:
                smallestNum = num_compare(smallestNum, intOne) ;
                break ;
            case 1:
                smallestNum = num_compare(smallestNum, intTwo) ;
                break ;
            case 2: 
                smallestNum = num_compare(smallestNum, intThree) ;
                break ;
            case 3:
                smallestNum = num_compare(smallestNum, intFour) ;
                break ;
            case 4: 
                smallestNum = num_compare(smallestNum, intFive) ;
                break ;
            case 5:
                smallestNum = num_compare(smallestNum, intSix) ;
                break ;
            case 6:
                smallestNum = num_compare(smallestNum, intSeven) ;
                break ;
            case 7:
                smallestNum = num_compare(smallestNum, intEight) ;
                break ;
            case 8:
                smallestNum = num_compare(smallestNum, intNine) ;
                break ;
            case 9:
                smallestNum = num_compare(smallestNum, intTen) ;
                break ;
            default:
                // The loop uses zero based indexing, but I think
                // starting from one is more intuitive to understand.
                cout << "ERROR: Invalid case triggered on iteration # " 
                    << (i + 1) << '\n' ;
        }       
    }
    cout << "The smallest number is " << smallestNum << '\n' ;

    return 0 ;
}

/*
Post Lab Reflection:

In this lab section I didn't use an array due to not going over them in class.

Using my existing knowledge about control structures and loops, I
designed a solution that uses my functionally validated
num_compare(..) function. Where on each iteration
a switch statement continously compared the current number with
the smallest number found.

Since the project accounts for a set number of input variables. This type of control structure and a
for loop is usable. But I feel like an array would have been possibly a better
choice because I wouldn't need to save 10 different variables.

*/