/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 08 Part 2
// Date Modified: 11-09-2026
// AI Models Used: No AI Used
//
/******************************************************/

#include <iostream>
using namespace std ;

// Function templates
template <typename T1, typename T2>
T1 findMax(T1 a, T2 b) {
    // Return which value is larger
    return (a > b) ? a : b ;
}

template <typename T1, typename T2>
void swapValues(T1 &a, T2 &b) {
    // Swap both values by reference
    T1 temp = a ;
    a = b ;
    b = temp ;
}

template <typename T>
void printArray(T arr[], int size){
    // Print all elements of a generic type array
    for (int cycle = 0 ; cycle < size ; cycle++)
    {
        cout << arr[cycle] << " " ;
    }
    cout << '\n' ;
}


int main()
{
    // Try findMax
    cout << "Max of 10 and 20 is: " << findMax(10, 20) << '\n' ;
    cout << "Max of 5.6 and 7.8 is: " << findMax(5.6, 7.8) << '\n' ;
    cout << "Max of 'apple' and 'orange' is: " << findMax("apple", "orange") << '\n' ;

    // Try swapValues
    int intA = 10 ;
    int intB = 20 ;

    cout << "Before Swapping - IntA: " << intA << ", intB: " << intB << '\n' ;
    swapValues(intA, intB) ;
    cout << "After Swapping - IntA: " << intA << ", intB: " << intB << '\n' ;

    // Try printArray
    int arrayInt[5] = {1, 2, 3, 4, 5} ;
    double arrayDouble[4] = {1.1, 2.2, 3.3, 4.4} ;

    cout << "Integer Array: " ;
    printArray(arrayInt, 5) ;

    cout << "Double Array: " ;
    printArray(arrayDouble, 4) ;
    cout << '\n' ;
 
    return 0 ;
}