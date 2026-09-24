# include <iostream>
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

// int main ()
// {
//     int numOne = 187 ;
//     int numTwo = 186 ;

//     cout << "The Smaller Number is: " << num_compare(numOne, numTwo) << '\n' ;
// }

int main ()
{
    const int ARRAY_SIZE = 10;
    int numList[ARRAY_SIZE] = {15, 23, 6, 9, 11, 45, 1, 3, 8, 17} ;
    int smallestNum ;

    smallestNum = numList[0] ;
    for (int k = 0 ; k < ARRAY_SIZE ; k++)
    {
        // NOTE: This isn't keeping the smallest number, but is instead
        // keeping every current number (numList[k]) on all iterations.
        if (num_compare(numList[0], numList[k]) <= numList[0])
            {
                smallestNum = numList[k] ;
            }
    }

    cout << "This is the smallest number: " << smallestNum << '\n' ;

    return 0 ;
}