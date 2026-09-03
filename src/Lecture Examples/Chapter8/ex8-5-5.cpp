// Some Restrictions on Array Processing
#include <iostream> 

using namespace std ;

int main()
{
    int myList[5] = {0, 4, 8, 12, 16} ; //Line 1
    int yourList[5] ;                   //Line 2

    // The statement in Line 1 declares and initializes the array myList, 
    // and the statement in Line 2 declares the array yourList. 
    // Note that these arrays are of the same type and have the same number 
    // of components. Suppose that you want to copy the elements of myList 
    // into the corresponding elements of yourList. 
    // The following statement is illegal
    //yourList = myList ; //illegal

    // To copy one array into another array, you must copy it 
    // component-wise—that is, one component at a time.
    for (int index = 0; index < 5; index++)
        yourList[index] = myList[index] ;

    for (int index = 0; index < 5; index++)
        cout << "yourList[" << index << "]: " << yourList[index] << endl ;
    cout << endl ;

    // Note that the following statements are legal in the sense that they 
    // do not generate a syntax error; however, they do not give the desired results.
    cout << myList << endl ;
    cout << yourList << endl ;

    // Output Interpretation: The addresses you see in the output 
    // (0x7ffe0c214e10 and 0x7ffe0c214e30) are memory addresses in 
    // hexadecimal format, and they point to the locations where 
    // the arrays myList and yourList are stored in memory.
    // - 0x7ffe0c214e10 is the memory address of myList[0], the first element of myList.
    // - 0x7ffe0c214e30 is the memory address of yourList[0], the first element of yourList.

    // Difference Between the Two Addresses: The difference between the two memory addresses is:
    // 0x7ffe0c214e30 - 0x7ffe0c214e10 = 0x20 (in hexadecimal)
    // 
    // Converting 0x20 to decimal gives 32. This means that the two arrays 
    // are 32 bytes apart in memory. Since each int typically occupies 4 bytes 
    // in most systems (on 64-bit machines, for example), and the arrays myList 
    // and yourList have 5 elements each, myList occupies 20 bytes (5 * 4), 
    // and the remaining space in memory likely causes the two arrays to be 
    // separated by 32 bytes.

    return 0 ;
}