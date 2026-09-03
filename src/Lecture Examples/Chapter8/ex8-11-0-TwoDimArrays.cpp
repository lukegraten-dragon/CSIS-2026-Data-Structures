// Two-dimensional array: A collection of a fixed number of components 
// arranged in rows and columns (that is, in two dimensions), wherein 
// all components are of the same type.

// The syntax for declaring a two-dimensional array is:
// dataType arrayName[intExp1][intExp2] ;
// wherein intExp1 and intExp2 are constant expressions yielding positive 
// integer values. The two expressions intExp1 and intExp2 specify the 
// number of rows and the number of columns, respectively, in the array.

#include <iostream>

using namespace std ;

int main() 
{
    // Declares a two-dimensional array sales of 10 rows and 5 columns, 
    // in which every component is of type double.
    double sales[10][5] ;

    // Accessing Array Components
    sales[5][3] = 5.18 ;

    // Two-Dimensional Array Initialization during Declaration
    int board[4][3] = {{2, 3, 1},
                       {15, 25, 13},
                       {20, 4, 7},
                       {11, 18, 14}} ;

    return 0 ;
}
