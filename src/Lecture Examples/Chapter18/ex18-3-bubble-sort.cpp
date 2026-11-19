/*
Bubble sort is a simple comparison-based sorting algorithm that repeatedly 
steps through a list of elements, compares adjacent elements, and swaps them 
if they are in the wrong order. The algorithm gets its name because larger 
elements "bubble up" to the top (end) of the list with each pass through the array.
*/
#include <iostream>

using namespace std ;

// Function to perform bubble sort
void bubbleSort(int list[], int length) 
{
    for (int i = 0; i < length - 1; i++) 
    {
        // Last i elements are already sorted
        for (int j = 0; j < length - i - 1; j++) 
        {
            if (list[j] > list[j + 1]) 
            {
                // Swap if the element found is greater than the next element
                int temp = list[j] ;
                list[j] = list[j + 1] ;
                list[j + 1] = temp ;
            }
        }
    }
}
/*
1. The bubbleSort function takes an integer array (list[]) and its length.
2. The outer loop (i) represents each pass through the array. 
   For each pass, the largest unsorted element "bubbles" to the correct position.
3. The inner loop (j) iterates through the unsorted portion of the array, 
   comparing adjacent elements.
   - If list[j] is greater than list[j + 1], the elements are swapped to position 
     the larger element correctly.
5. After each pass, the largest unsorted element is in the correct position, 
   so the next pass only needs to sort the remaining unsorted portion (length - i - 1).
*/

int main() 
{
    int list[] = {64, 34, 25, 12, 22, 11, 90} ;
    int length = sizeof(list) / sizeof(list[0]) ;

    cout << "Unsorted array: " ;
    for (int i = 0; i < length; i++) 
    {
        cout << list[i] << " " ;
    }
    cout << endl ;

    bubbleSort(list, length) ;

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
4. bubbleSort is called with list and length as arguments.
5. After sorting, the sorted array is printed.
*/

/*
Complexity Analysis
1. Time Complexity:
   - Best Case: O(n), if the array is already sorted and the algorithm 
     is optimized to detect this case.
   - Worst and Average Case: O(n^2), because each element may need to 
     be compared with every other element.

2. Space Complexity: O(1), as bubble sort is an in-place sorting algorithm 
   and requires no extra memory.
*/

/*
Key Points
1. Bubble Sort is easy to understand and implement, making it suitable for 
   small datasets or educational purposes.
2. Limitations: Inefficient on large datasets due to its O(n^2) time complexity.
*/

/*
Example Walkthrough

Suppose we have an array: [5, 3, 8, 4, 2].

First Pass:
    Compare 5 and 3 --> swap to get [3, 5, 8, 4, 2]
    Compare 5 and 8 --> no swap
    Compare 8 and 4 --> swap to get [3, 5, 4, 8, 2]
    Compare 8 and 2 --> swap to get [3, 5, 4, 2, 8]
    Now, 8 is in its correct position.

Second Pass:
    Compare 3 and 5 --> no swap
    Compare 5 and 4 --> swap to get [3, 4, 5, 2, 8]
    Compare 5 and 2 --> swap to get [3, 4, 2, 5, 8]
    Now, 5 is in its correct position.

Third Pass:
    Compare 3 and 4 --> no swap
    Compare 4 and 2 --> swap to get [3, 2, 4, 5, 8]
    Now, 4 is in its correct position.

Fourth Pass:
    Compare 3 and 2 --> swap to get [2, 3, 4, 5, 8]
    Now, 3 is in its correct position.
    The array is now fully sorted: [2, 3, 4, 5, 8].
*/
