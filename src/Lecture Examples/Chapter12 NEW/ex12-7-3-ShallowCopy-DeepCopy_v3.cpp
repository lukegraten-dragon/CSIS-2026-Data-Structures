// Shallow versus Deep Copy and Pointers

#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    // Shallow copy
    {
        int *first ;
        int *second ;

        first = new int[5] ;
        /*
                        +----+----+----+----+----+
            first ---->| ?? | ?? | ?? | ?? | ?? |
                        +----+----+----+----+----+

            The five integers have been allocated but not initialized.
        */

        for (int i = 0; i < 5; i++)
            first[i] = i + 1 ;
        /*
                        +----+----+----+----+----+
            first ---->|  1 |  2 |  3 |  4 |  5 |
                        +----+----+----+----+----+
        */

        second = first ;
        /*
            The assignment copies the address stored in first into second.
            It does not create another array.

            first  -------+
                          |
                          v
                     +----+----+----+----+----+
                     |  1 |  2 |  3 |  4 |  5 |
                     +----+----+----+----+----+
                          ^
                          |
            second -------+

            Both pointers refer to the same dynamically allocated array.
            Changing an element through either pointer changes the same data.
            This is a shallow copy.
        */

        delete [] second ;
        /*
            The array shared by first and second has now been deallocated.

            first  -------+
                          |
                          v
                    [ Deallocated array ]
                          ^
                          |
            second -------+

            Neither pointer is automatically set to nullptr. Both still
            hold the address of the released array and are dangling pointers.
            Dereferencing either pointer or deleting the same array again
            would cause undefined behavior.
        */

        first = nullptr ;
        second = nullptr ;
    }

    // Deep copy
    {
        int *first ;
        int *second ;

        first = new int[5] ;

        for (int i = 0; i < 5; i++)
            first[i] = i + 1 ;

        second = new int[10] ;

        for (int j = 0; j < 5; j++)
            second[j] = first[j] ;
        /*
            new int[10] allocates a separate array of 10 integers.
            The loop copies five elements from first into second.

            first  ---> +----+----+----+----+----+
                        |  1 |  2 |  3 |  4 |  5 |
                        +----+----+----+----+----+
            Index          0    1    2    3    4

            second ---> +----+----+----+----+----+----+----+----+----+----+
                        |  1 |  2 |  3 |  4 |  5 | ?? | ?? | ?? | ?? | ?? |
                        +----+----+----+----+----+----+----+----+----+----+
            Index          0    1    2    3    4    5    6    7    8    9

            Elements second[5] through second[9] are not initialized.

            The two pointers now refer to separate arrays. Changing an
            element in second does not change the corresponding element
            in first. Deleting one array does not release the other.
            The five initialized elements have been copied independently.
        */

        delete [] second ;
        delete [] first ;
    }

    return 0 ;
}
