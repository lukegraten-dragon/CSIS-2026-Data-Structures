/*
Selection sort is an in-place comparison-based sorting algorithm 
that divides the list into a sorted and an unsorted part. 
It repeatedly selects the smallest (or largest, depending on 
sorting order) element from the unsorted part and moves it to 
the end of the sorted part.
*/
#include <iostream>
using namespace std ;

// Function to perform selection sort
void selectionSort(int list[], int length) 
{
    for (int i = 0; i < length - 1; i++) 
    {
        int minIndex = i ; // Assume the minimum is at the current position

        // Find the smallest element in the unsorted portion of the list
        for (int j = i + 1; j < length; j++) 
        {
            if (list[j] < list[minIndex]) 
            {
                minIndex = j ; // Update minIndex if a smaller element is found
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        int temp = list[i] ;
        list[i] = list[minIndex] ;
        list[minIndex] = temp ;
    }
}
/*
1. The selectionSort function takes an integer array (list[]) and its length.
2. The outer loop (i) represents each position in the array where the next 
   smallest element should be placed.
3. minIndex is initialized to i at the beginning of each pass, assuming the 
   current position has the smallest element.
4. The inner loop (j) iterates through the unsorted portion of the list, looking 
   for the smallest element. If a smaller element is found, minIndex is updated.
5. After finding the smallest element in the unsorted portion, a swap is 
   performed to place it in the correct position at index i.
*/

int main() 
{
    int list[] = {64, 25, 12, 22, 11} ;
    int length = sizeof(list) / sizeof(list[0]) ;

    cout << "Unsorted array: " ;
    for (int i = 0; i < length; i++) 
    {
        cout << list[i] << " " ;
    }
    cout << endl ;

    selectionSort(list, length) ;

    cout << "Sorted array  : " ;
    for (int i = 0; i < length; i++) 
    {
        cout << list[i] << " " ;
    }
    cout << endl ;

    return 0 ;
}
/*
Main Function:

1. An example array list[] is defined with unsorted integers.
2. length is calculated using sizeof(list) / sizeof(list[0]).
3. The unsorted array is printed to show the initial state.
4. selectionSort is called with list and length.
5. After sorting, the sorted array is printed.
*/

/*
Complexity Analysis
1. Time Complexity: O(n^2) in the best, worst, and average cases because 
   each element is compared to every other element at least once.
2. Space Complexity: O(1), as selection sort is an in-place sorting algorithm 
   that does not require additional memory beyond temporary variables.
*/

/*
Key Points
1. Selection Sort repeatedly finds the smallest (or largest) element 
   from the unsorted portion and places it in the sorted portion.
2. Efficiency: Selection sort is inefficient on large datasets 
   due to its O(n^2) time complexity.
3. Use Case: Suitable for small datasets or when memory usage is 
   a priority due to its in-place
*/

/*
Example Walkthrough:

Consider an array [64, 25, 12, 22, 11].

First Pass (find the smallest element in the entire array):
    The smallest element is 11. Swap it with 64.
    Array after swap: [11, 25, 12, 22, 64].
    Now, 11 is in the sorted part.

Second Pass (find the smallest element in the remaining unsorted portion [25, 12, 22, 64]):
    The smallest element is 12. Swap it with 25.
    Array after swap: [11, 12, 25, 22, 64].

Third Pass (find the smallest element in [25, 22, 64]):
    The smallest element is 22. Swap it with 25.
    Array after swap: [11, 12, 22, 25, 64].

Fourth Pass (only [25, 64] remains):
    The smallest element is 25. No swap needed since it’s already in place.
    Array after final pass: [11, 12, 22, 25, 64].

Now the array is fully sorted.
*/
