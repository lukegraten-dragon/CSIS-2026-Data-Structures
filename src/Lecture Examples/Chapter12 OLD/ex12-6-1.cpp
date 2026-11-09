#include <iostream>

using namespace std ;

int main()
{
    int *intList ;                 //Line 1
    int arraySize ;                //Line 2
    cout << "Enter array size: " ; //Line 3
    cin >> arraySize ;             //Line 4
    cout << endl ;                 //Line 5
    intList = new int[arraySize] ; //Line 6

    /*
    The statement in Line 1 declares intList to be a pointer of type int, and the
    statement in Line 2 declares arraySize to be an int variable. The statement in Line 3
    prompts the user to enter the size of the array, and the statement in Line 4 inputs the
    array size into the variable arraySize. The statement in Line 6 creates an array of the
    size specified by arraySize, and the base address of the array is stored in intList.
    From this point on, you can treat intList just like any other array. For example, you
    can use the array notation to process the elements of intList and pass intList as a
    parameter to the function.
    */

    cout << "Initializing an int array, intList" << endl ;
    for (int i=0; i<arraySize; i++)
    {
        intList[i] = i + 1 ;
        cout << "intList[" << i << "]: " << intList[i] << endl ;
    }

    return 0 ;
}