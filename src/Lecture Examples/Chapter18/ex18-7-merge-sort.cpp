/*
Merge sort is an efficient, stable, and comparison-based sorting algorithm 
that follows the divide-and-conquer approach. It divides the array into 
smaller subarrays, sorts them, and then merges them back together in sorted order.
*/
#include <iostream>

using namespace std ;

// Function to merge two subarrays of list[]
void merge(int list[], int left, int mid, int right) 
{
    int n1 = mid - left + 1 ; // Size of left subarray
    int n2 = right - mid ;    // Size of right subarray

    // Create temporary arrays
    int leftArray[n1], rightArray[n2] ;

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++) 
    {
        leftArray[i] = list[left + i] ;
    }
    for (int j = 0; j < n2; j++) 
    {
        rightArray[j] = list[mid + 1 + j] ;
    }

    // Merge the temporary arrays back into list[left..right]
    int i = 0, j = 0, k = left ;
    while (i < n1 && j < n2) 
    {
        if (leftArray[i] <= rightArray[j]) 
        {
            list[k] = leftArray[i] ;
            i++ ;
        } 
        else 
        {
            list[k] = rightArray[j] ;
            j++ ;
        }
        k++ ;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) 
    {
        list[k] = leftArray[i] ;
        i++ ;
        k++ ;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) 
    {
        list[k] = rightArray[j] ;
        j++ ;
        k++ ;
    }
}
/*
Merge Function:

1. The merge function merges two sorted subarrays (leftArray and rightArray) 
   into the main array list[].
2. n1 and n2 are calculated as the sizes of the two subarrays.
3. Temporary arrays leftArray and rightArray are created and populated with 
   the elements from list[].
4. The merging process compares elements from both subarrays, placing the 
   smaller element in the main array list[] in sorted order.
5. After the main merging loop, any remaining elements in leftArray or rightArray 
   are copied back to list[].
*/

// Merge sort function
void mergeSort(int list[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2 ;

        // Recursively sort first and second halves
        mergeSort(list, left, mid) ;
        mergeSort(list, mid + 1, right) ;

        // Merge the sorted halves
        merge(list, left, mid, right) ;
    }
}
/*
Merge Sort Function:

1. The mergeSort function is a recursive function that splits the array into halves.
2. mid is calculated as the midpoint of the current subarray.
3. The function recursively calls itself on the left half (left to mid) and the right 
   half (mid + 1 to right).
4. After sorting both halves, it merges them back together using the merge function.
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

    mergeSort(list, 0, length - 1) ;

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
2. mergeSort is called with the list, 0, and length - 1 as arguments.
3. Both the unsorted and sorted arrays are printed.
*/

/*
Complexity Analysis
1. Time Complexity:
   - Best, Worst, and Average Case: O(nlogn) because the array is repeatedly 
     split in half, and the merging step takes linear time.
2. Space Complexity: O(n) due to the temporary arrays created during the merge process.
*/

/*
Characteristics of Merge Sort

1. Divide and Conquer: Merge sort splits the array into smaller parts, 
   sorts each part, and then merges them.
2. Stable: Merge sort preserves the relative order of equal elements.
3. Not In-Place: Merge sort requires extra space for temporary arrays, 
   making it less space-efficient than some other sorting algorithms.
*/

/*
How Merge Sort Works

Merge sort works in three primary steps:

1. Divide:
   - The array is split into two roughly equal halves. This division continues 
     recursively until each subarray contains only a single element (or no elements), 
     which is inherently sorted.

2. Conquer (Sort):
   - Once the array has been divided into single-element subarrays, the algorithm 
     begins merging these subarrays. During the merging process, it places elements 
     in sorted order, creating larger sorted subarrays step-by-step.

3. Combine (Merge):
   - Finally, the algorithm merges all the sorted subarrays back together, resulting 
     in a single sorted array.
*/

/*
Example of Merge Sort

Consider the array [38, 27, 43, 3, 9, 82, 10].

1. Divide:

   - First, divide the array into two halves: [38, 27, 43] and [3, 9, 82, 10].
   - Continue dividing until each subarray has one element:
       - [38, 27, 43] becomes [38], [27], [43].
       - [3, 9, 82, 10] becomes [3], [9], [82], [10].

2. Conquer (Merge):

   - Begin merging subarrays:
       - Merge [38] and [27] to get [27, 38].
       - Merge [27, 38] with [43] to get [27, 38, 43].
       - Merge [3] and [9] to get [3, 9].
       - Merge [82] and [10] to get [10, 82].
       - Merge [3, 9] with [10, 82] to get [3, 9, 10, 82].

3. Combine (Final Merge):
   - Finally, merge [27, 38, 43] and [3, 9, 10, 82] to get the fully sorted array 
     [3, 9, 10, 27, 38, 43, 82].
*/
