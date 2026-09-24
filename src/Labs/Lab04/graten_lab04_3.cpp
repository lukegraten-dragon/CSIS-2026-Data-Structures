/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 04 Part 3
// Date Modified: 09-24-2026
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

int main ()
{   
    const int ARRAY_SIZE = 10 ;
    int numList[ARRAY_SIZE] ; // e.g. 0 1 2 3 4 5 6 7 8 9 Run loops 10 times
    int arrayValue ;
    int smallestNum ;

    cout << "Enter 10 numbers: " ;

    for (int i = 0 ; i < ARRAY_SIZE ; i++)
    {
        // Add values to each index in the array
        cin >> arrayValue ;

        numList[i] = arrayValue ;
    } 

    // // Print out the values in the indexes
    // for (int j = 0 ; j < ARRAY_SIZE ; j++)
    // {
    //     cout << numList[j] ;
    //     cout << " " ;
    // }
    cout << '\n' ;

    // 15 23 6 9 11 45 1 3 8 17
    for (int k = 0 ; k < ARRAY_SIZE ; k++)
    {
        if (num_compare(numList[0], numList[k]) <= numList[0])
            {
                smallestNum = numList[k] ;
            }
    }

    cout << "The smallest number is " << smallestNum << '\n' ;

    return 0 ;
}