/*
The binary search algorithm is a highly efficient method for finding 
a specific element in a sorted array. Unlike sequential search, which 
checks each element one-by-one, binary search leverages the sorted 
nature of the array to "divide and conquer," cutting the search space 
in half at each step. This drastically reduces the number of comparisons, 
making binary search one of the fastest ways to search in a sorted dataset.
*/
#include <iostream>

using namespace std ;

// Function to perform binary search
int binarySearch(const int list[], int length, const int &item) 
{
    int left = 0 ;
    int right = length - 1 ;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2 ; // Prevents overflow

        // Check if item is at the middle position
        if (list[mid] == item) 
        {
            return mid ; // Return index if item is found
        }
        // If item is greater, ignore the left half
        else if (list[mid] < item) 
        {
            left = mid + 1 ;
        }
        // If item is smaller, ignore the right half
        else 
        {
            right = mid - 1 ;
        }
    }
    return -1 ; // Return -1 if item is not found
}
/*
1. The binarySearch function takes a sorted array (list[]), its length, 
   and a target item to search.
2. left is initialized to 0, representing the start of the array, and 
   right is initialized to length - 1, representing the end.
3. While left is less than or equal to right:
   - mid is calculated as left + (right - left) / 2 to avoid overflow.
   - If the item at the mid index is equal to item, the function returns mid.
   - If item is greater than list[mid], left is updated to mid + 1 (ignoring the left half).
   - If item is smaller than list[mid], right is updated to mid - 1 (ignoring the right half).
3. If the loop ends without finding the item, -1 is returned, indicating 
   the item is not in the array.
*/

int main() 
{
    const int list[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100} ; // Sorted array
    int length = sizeof(list) / sizeof(list[0]) ;
    int target ;

    cout << "Enter the number to search: " ;
    cin >> target ;

    int result = binarySearch(list, length, target) ;

    if (result != -1) 
    {
        cout << "Element found at index " << result << endl ;
    } 
    else 
    {
        cout << "Element not found in the array." << endl ;
    }

    return 0 ;
}
/*
Main Function:
1. A sorted array list[] is defined.
2. length is calculated using sizeof(list) / sizeof(list[0]).
3. The user is prompted to enter the number to search for.
4. binarySearch is called with list, length, and target.
5. If the target is found, its index is printed; otherwise, 
   a message indicates the element is not found.
*/

/*
Complexity
1. Time Complexity: O(logn), as the array is divided in half during each step.
2. Space Complexity: O(1), as no additional space is required beyond the input array.

Summary
Binary search is efficient for finding elements in sorted arrays, and it performs 
significantly faster than sequential search for large datasets. 
However, the array must be sorted for binary search to work.
*/
