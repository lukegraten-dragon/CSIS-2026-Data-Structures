/*
Insertion sort is a simple sorting algorithm that builds the sorted array 
one element at a time by repeatedly taking the next unsorted element and 
inserting it into its correct position within the already sorted portion.
*/
#include <iostream>

using namespace std ;

// Function to perform insertion sort
void insertionSort(int list[], int length) 
{
    for (int i = 1; i < length; i++) 
    {
        int key = list[i] ; // Current element to be inserted
        int j = i - 1 ;

        // Move elements of list[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && list[j] > key) 
        {
            list[j + 1] = list[j] ;
            j = j - 1 ;
        }
        list[j + 1] = key ; // Insert the key at its correct position
    }
}
/*
1. The insertionSort function takes an integer array (list[]) and its length 
   as input.
2. The outer loop (i) iterates over each element starting from the 
   second element (i = 1) because we consider the first element to be 
   "already sorted."
3. key is assigned to list[i], the element to be inserted into the sorted 
   portion of the array.
4. The inner while loop compares key with elements in the sorted portion 
   (all elements from list[0] to list[i-1]).
   - If any of these elements are greater than key, they are shifted one 
     position to the right to make room for key.
   - This continues until the correct insertion position for key is found.
5. Finally, key is placed in its correct position within the sorted portion.
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

    insertionSort(list, length) ;

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
4. insertionSort is called with list and length.
5. After sorting, the sorted array is printed.
*/

/*
Complexity Analysis
1. Time Complexity:
  - Best Case: O(n) if the array is already sorted, as it only performs 
    a single comparison per element.
  - Worst and Average Case: O(n^2) because each element may need to be 
    compared and shifted up to n times.
2. Space Complexity: O(1), as insertion sort is an in-place sorting algorithm 
   requiring no additional memory beyond a few temporary variables.
*/

/*
Key Points

1. Advantages:
   - Efficient for small datasets and nearly sorted data.
   - Simple to implement with minimal overhead.
   - Stable and in-place, making it suitable for situations where space is limited.

2. Limitations:
   - Inefficient for large datasets because of its O(n^2) time complexity.
   - Not as fast as more complex algorithms like quicksort or mergesort 
     for large, unsorted datasets.
*/

/*
Example Walkthrough

Consider sorting the array [5, 2, 9, 1, 5, 6]:

First Pass (key = 2):
    The sorted part is [5], and 2 is the key.
    Compare 2 with 5 (move 5 to the right) to make space for 2.
    Insert 2, resulting in [2, 5, 9, 1, 5, 6].

Second Pass (key = 9):
    Sorted part is [2, 5], and 9 is the key.
    9 is already in the correct position since it is greater than all elements in the sorted part.
    Array remains [2, 5, 9, 1, 5, 6].

Third Pass (key = 1):
    Sorted part is [2, 5, 9], and 1 is the key.
    Compare 1 with 9, 5, and 2 (shift each of them right).
    Insert 1 at the beginning, resulting in [1, 2, 5, 9, 5, 6].

Fourth Pass (key = 5):
    Sorted part is [1, 2, 5, 9], and 5 is the key.
    Move 9 to the right, then insert 5.
    Resulting array: [1, 2, 5, 5, 9, 6].

Fifth Pass (key = 6):
    Sorted part is [1, 2, 5, 5, 9], and 6 is the key.
    Move 9 to the right and insert 6.
    Final sorted array: [1, 2, 5, 5, 6, 9].
*/
