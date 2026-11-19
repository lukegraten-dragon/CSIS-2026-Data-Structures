/*
Quick sort is a highly efficient, divide-and-conquer sorting algorithm 
that selects a "pivot" element and partitions the array into two subarrays, 
placing elements less than the pivot on one side and elements greater than 
the pivot on the other. This process is repeated recursively on the subarrays.
*/
#include <iostream>

using namespace std ;

// Function to partition the array
int partition(int list[], int low, int high) 
{
    int pivot = list[high] ; // Pivot element
    int i = low - 1 ; // Index of smaller element

    for (int j = low; j < high; j++) 
    {
        // If current element is less than or equal to pivot
        if (list[j] <= pivot) 
        {
            i++ ;
            // Swap list[i] and list[j]
            int temp = list[i] ;
            list[i] = list[j] ;
            list[j] = temp ;
        }
    }
    // Swap list[i+1] and list[high] (or pivot)
    int temp = list[i + 1] ;
    list[i + 1] = list[high] ;
    list[high] = temp ;
    
    return i + 1 ; // Return the partition index
}
/*
Partition Function:

1. The partition function takes the array, the low index, and the high index.
2. The pivot is chosen as the last element in the array (list[high]).
3. The variable i is initialized to low - 1 to track the position where elements 
   less than the pivot should go.
4. The for loop iterates from low to high - 1. If an element is less than or 
   equal to the pivot, it swaps the element with list[i + 1].
5. After the loop, the pivot element is placed at its correct position (between 
   smaller and larger elements) by swapping it with list[i + 1].
6. The function returns i + 1, the index of the pivot’s final position.
*/

// Quick sort function
void quickSort(int list[], int low, int high) 
{
    if (low < high) 
    {
        // Partition the array and get the partitioning index
        int pi = partition(list, low, high) ;

        // Recursively sort elements before and after partition
        quickSort(list, low, pi - 1) ;
        quickSort(list, pi + 1, high) ;
    }
}
/*
Quick Sort Function:

1. The quickSort function takes the array, low, and high indices.
2. If low < high, the array is partitioned, and the pivot index (pi) is returned.
3. Quick sort is then called recursively on the left part (low to pi - 1) and 
   the right part (pi + 1 to high).
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

    quickSort(list, 0, length - 1) ;

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
2. The quickSort function is called with the list, 0, and length - 1.
3. Both the unsorted and sorted arrays are printed.
*/

/*
Complexity Analysis
1. Time Complexity:
   - Best and Average Case: O(nlogn), as the array is split approximately 
     in half at each recursive call.
   - Worst Case: O(n^2), if the pivot divides the array into unbalanced parts 
     (e.g., if the array is already sorted or reverse-sorted).

2. Space Complexity: O(logn) for the recursive call stack, making it an efficient 
   in-place sorting algorithm.
*/

/*
Example of Quick Sort

Consider sorting the array [10, 7, 8, 9, 1, 5]:

1. Choose a Pivot:
   - Let’s select 5 as the pivot (last element).

2. Partitioning:
   - Rearrange elements so all elements less than 5 are to its left and 
     all elements greater than 5 are to its right.
   - After partitioning, the array might look like [1, 5, 8, 9, 7, 10], 
     with 5 in its correct position.

3. Recursive Sorting:
   - Apply quick sort on the left subarray [1] and right subarray [8, 9, 7, 10].
   - This process repeats, choosing pivots and partitioning each subarray 
     until the entire array is sorted.
   - The final sorted array is [1, 5, 7, 8, 9, 10].
*/

/*
Characteristics of Quick Sort

1. In-Place: Quick sort does not require additional storage, as it sorts 
   elements within the original array.
2. Unstable: Quick sort does not preserve the relative order of equal elements 
   because it involves swapping elements around the pivot.
3. Divide and Conquer: It recursively divides the array and conquers by sorting 
   each part, allowing for efficient handling of large datasets.
*/

/*
Optimization Techniques

1. Pivot Selection: Randomly choosing the pivot or using the median of three 
   elements (first, middle, and last) can help avoid the worst-case scenario.
2. Hybrid Approaches: For small subarrays, insertion sort may be faster. 
   Many implementations switch to insertion sort for subarrays below a certain 
   threshold size.
*/
