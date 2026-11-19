/*
Heap sort is a comparison-based sorting algorithm that uses a binary heap data 
structure. It builds a max heap (or min heap for descending order), then repeatedly 
extracts the maximum (or minimum) element, placing it at the end of the list, and 
re-heapifies the remaining elements.
*/
#include <iostream>

using namespace std ;

// Function to heapify a subtree rooted at node i in list[]
void heapify(int list[], int n, int i) 
{
    int largest = i ;         // Initialize largest as root
    int left = 2 * i + 1 ;    // Left child index
    int right = 2 * i + 2 ;   // Right child index

    // If left child is larger than root
    if (left < n && list[left] > list[largest]) 
    {
        largest = left ;
    }

    // If right child is larger than largest so far
    if (right < n && list[right] > list[largest]) 
    {
        largest = right ;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) 
    {
        swap(list[i], list[largest]) ;
        heapify(list, n, largest) ; // Recursively heapify the affected subtree
    }
}
/*
Heapify Function:

1. The heapify function ensures that the subtree rooted at index i follows 
   the max heap property.
2. largest is initialized as i (root of the subtree), and left and right 
   represent the indices of the left and right children, respectively.
3. If the left child is greater than the root, largest is updated to the 
   left child’s index.
4. If the right child is larger than the current largest, largest is updated 
   to the right child’s index.
5. If largest is not the root, the elements at i and largest are swapped, 
   and heapify is called recursively to ensure the subtree rooted at largest 
   follows the max heap property.
*/

// Function to perform heap sort
void heapSort(int list[], int n) 
{
    // Build the max heap
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(list, n, i) ;
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) 
    {
        // Move current root to end
        swap(list[0], list[i]) ;

        // Call heapify on the reduced heap
        heapify(list, i, 0) ;
    }
}
/*
Heap Sort Function:

1. heapSort first builds a max heap by calling heapify on all non-leaf nodes 
   from bottom to top.
2. Then, it repeatedly extracts the maximum element (the root of the heap), 
   swaps it with the last element in the heap, reduces the heap size by one, 
   and calls heapify on the reduced heap to restore the max heap property.
3. This process continues until the entire array is sorted.
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

    heapSort(list, length) ;

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
2. The heapSort function is called with list and length.
3. Both the unsorted and sorted arrays are printed.
*/

/*
Complexity Analysis

1. Time Complexity:
   - Building the Heap: O(n)
   - Heap Sort Process: O(nlogn) because each extraction and heapification 
     operation takes O(logn) time and occurs n times.
   - Overall: O(nlogn) in the best, worst, and average cases.

2. Space Complexity: O(1) as it is an in-place sorting algorithm that doesn’t 
   require additional memory.
*/

/*
Characteristics of Heap Sort

1. In-Place: Heap sort does not require extra storage, making it efficient 
   for memory usage.
2. Not Stable: Heap sort does not preserve the relative order of equal elements 
   because of the swapping process.
3. Efficient for Large Data Sets: Due to its O(nlogn) time complexity, heap sort 
   is efficient for large datasets and provides consistent performance.
*/

/*
Example of Heap Sort

Consider the array [12, 11, 13, 5, 6, 7].

1. Build the Max Heap:
   - The array is converted into a max heap, so it might look like [13, 11, 12, 5, 6, 7].

2. Extract the Maximum Element:
   - Swap the root (13) with the last element (7), giving [7, 11, 12, 5, 6, 13].
   - Reduce the heap size and heapify the root to restore the max heap property, 
     resulting in [12, 11, 7, 5, 6, 13].

3. Repeat Until Sorted:
   - Continue extracting the maximum element, swapping, and heapifying until the 
     entire array is sorted.
   - The final sorted array is [5, 6, 7, 11, 12, 13].
*/
