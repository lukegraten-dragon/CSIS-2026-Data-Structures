#include <iostream>

using namespace std ;

int seqSearch(const int list[], int length, const int &item) 
{
    for (int i = 0; i < length; i++) 
    {
        if (list[i] == item) 
        {
            return i ; // Return the index if item is found
        }
    }
    return -1 ; // Return -1 if item is not found
}
/*
1. The sequentialSearch function takes a vector of integers (list) and 
   an integer target as parameters.
2. A for loop iterates through each element of the vector.
3. If the current element matches the target, the index is returned.
4. If the loop completes without finding the target, -1 is returned 
   to indicate the target was not found.
*/

int main() 
{
    const int list[] = {10, 25, 32, 45, 60, 70, 85} ; // Example array, list
    int length = sizeof(list) / sizeof(list[0]) ;
    int target ;

    cout << "Enter the number to search: " ;
    cin >> target ;

    int result = seqSearch(list, length, target) ;

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
1. An example array (list) is defined with several integer elements.
2. The user is prompted to enter the number to search for.
3. The sequentialSearch function is called with list and target.
4. If the target is found, the index is printed. Otherwise, a message 
   indicating the element was not found is displayed.
*/

/*
Complexity
1. Time Complexity: O(n), where n is the number of elements in the array, 
   because each element may need to be checked once.
2. Space Complexity: O(1), as no additional data structures are used beyond 
   the input array.

Summary
Sequential search is simple but may be inefficient for large datasets, 
as each element must be checked in the worst case. However, it is easy 
to implement and is effective for small or unsorted datasets.
*/
