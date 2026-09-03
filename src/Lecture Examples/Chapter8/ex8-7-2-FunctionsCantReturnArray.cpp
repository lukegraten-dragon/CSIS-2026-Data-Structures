// C++ does not allow functions to return a value of the type array. 
// Note that the functions sumArray and indexLargestElement described 
// earlier return values of type int.

#include <iostream>

using namespace std ;

// This function update values of an int array.
void updateArray1 (int int_array[], int size) ;

//int intArray[3] = {0, 0, 0} ;
//int[] updateArray2(int int_array[], int size) ; // illegal

int main()
{
    int num[] = {1, 2, 3} ;

    cout << "Before calling changeArray()" << endl
         << "num[0]: "<< num[0] << endl
         << "num[1]: "<< num[1] << endl
         << "num[2]: "<< num[2] << endl
         << endl ;

    updateArray1(num, size(num)) ;

    cout << "After calling changeArray()" << endl
         << "num[0]: "<< num[0] << endl
         << "num[1]: "<< num[1] << endl
         << "num[2]: "<< num[2] << endl
         << endl ;

    return 0 ;
}

void updateArray1 (int int_array[], int size)
{
    for (int i=0; i<size; i++)
        int_array[i] = int_array[i] + 3 ;
}