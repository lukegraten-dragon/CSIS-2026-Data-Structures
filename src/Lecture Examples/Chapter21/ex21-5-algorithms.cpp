#include <iostream>
#include <vector>
#include <algorithm> // For STL algorithms
#include <numeric>   // For accumulate

using namespace std ;

int main()
{
    // Declare and initialize a vector
    vector<int> numbers = {10, 20, 15, 25, 10, 30, 5} ;

    // Display the original vector
    cout << "Original vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Sorting the vector
    sort(numbers.begin(), numbers.end()) ;
    cout << "Sorted vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Reversing the vector
    reverse(numbers.begin(), numbers.end()) ;
    cout << "Reversed vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Finding an element
    int value_to_find = 15 ;
    auto it = find(numbers.begin(), numbers.end(), value_to_find) ;
    if (it != numbers.end())
    {
        cout << "Element " << value_to_find << " found at position: " 
             << distance(numbers.begin(), it) << endl ;
    }
    else
    {
        cout << "Element " << value_to_find << " not found." << endl ;
    }

    // Counting occurrences of an element
    int value_to_count = 10 ;
    int count_occurrences = count(numbers.begin(), numbers.end(), value_to_count) ;
    cout << "Element " << value_to_count << " occurs " 
         << count_occurrences << " times in the vector." << endl ;

    // Calculating the sum of all elements
    int sum = accumulate(numbers.begin(), numbers.end(), 0) ;
    cout << "Sum of all elements: " << sum << endl ;

    // Finding the maximum and minimum elements
    auto max_element_it = max_element(numbers.begin(), numbers.end()) ;
    auto min_element_it = min_element(numbers.begin(), numbers.end()) ;
    cout << "Maximum element: " << *max_element_it << endl ;
    cout << "Minimum element: " << *min_element_it << endl ;

    // Removing duplicates (requires a sorted vector)
    sort(numbers.begin(), numbers.end()) ; // Sort before removing duplicates
    auto last = unique(numbers.begin(), numbers.end()) ;
    numbers.erase(last, numbers.end()) ;
    cout << "Vector after removing duplicates: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    return 0 ;
}
