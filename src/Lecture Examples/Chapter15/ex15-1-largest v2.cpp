//Largest element in an array

#include <iostream>

using namespace std ;

int largest(const int list[], int lowerIndex, int upperIndex) ;

int main()
{
    int intArray[10] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8} ;
    
    cout << "The largest element in intArray: "
         << largest(intArray, 0, 9) << endl ;
    
    return 0 ;
}

/*
Explanation of the Program

1. Base Case: If lowerIndex equals upperIndex, the sublist has only one element,
   so list[lowerIndex] is the largest element in that sublist.
2. Recursive Case: The function calls itself with lowerIndex + 1 while keeping
   upperIndex unchanged, reducing the search range by one element.
3. After the recursive call returns the largest value in the remaining sublist
   (stored in max), we compare list[lowerIndex] with max.
   - If list[lowerIndex] is greater than or equal to max, return list[lowerIndex].
   - Otherwise, return max.

Example: largest(list, 0, 3)
Assume list = {23, 43, 35, 38}

Recursive Calls (going deeper):
largest(list, 0, 3)
  -> largest(list, 1, 3)
  -> largest(list, 2, 3)
  -> largest(list, 3, 3)  // Base Case: returns 38

Unwinding (returning to earlier calls):
largest(list, 2, 3): max(35, 38) = 38
largest(list, 1, 3): max(43, 38) = 43
largest(list, 0, 3): max(23, 43) = 43

Final result: 43

Note: This function assumes valid indexes with 0 <= lowerIndex <= upperIndex
and upperIndex within the array bounds. It does not handle an empty range.
*/

int largest(const int list[], int lowerIndex, int upperIndex)
{
    int max ;

    // Base case: if there's only one element, it is the largest
    if (lowerIndex == upperIndex) //size of the sublist is one
        return list[lowerIndex] ;
    else
    {
        // Recursive case: find the largest in the remaining part of the array
        max = largest(list, lowerIndex + 1, upperIndex) ;

        if (list[lowerIndex] >= max)
            return list[lowerIndex] ;
        else
            return max ;
    }
}