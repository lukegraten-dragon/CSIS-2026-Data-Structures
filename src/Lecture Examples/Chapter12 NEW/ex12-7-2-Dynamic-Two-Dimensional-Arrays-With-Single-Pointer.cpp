// Dynamic Two-Dimensional Arrays with A Single Pointer

#include <iostream>                                //Line 1
#include <iomanip>                                 //Line 2

using namespace std ;                              //Line 3

void fill(int *p, int rowSize, int columnSize) ;   //Line 4

void print(int *p, int rowSize, int columnSize) ;  //Line 5

int main()                                         //Line 6
{                                                  //Line 7
    int *board ;                                   //Line 8
    int rows ;                                     //Line 9
    int columns ;                                  //Line 10

    cout << "Line 11: Enter the number of rows "
         <<"and columns: " ;                       //Line 11
    
    cin >> rows >> columns ;                       //Line 12
    
    cout << endl ;                                 //Line 13
    
    // Create a contiguous block of memory for the 2D array
    board = new int[rows * columns] ;              //Line 14

    // Insert elements into board
    fill(board, rows, columns) ;                   //Line 15
    cout << "Line 16: Board:" << endl ;            //Line 16

    // Output the elements of board
    print(board, rows, columns) ;                  //Line 17

    // Deallocate the memory
    delete[] board;                                //Line 18

    return 0 ;                                     //Line 19
}                                                  //Line 20

void fill(int *p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        cout << "Enter " << columnSize << " number(s)"
             << " for row number " << row << ": " ;
        
        for (int col = 0; col < columnSize; col++)
        {
            // Access the 2D array using the formula (row * columnSize + col)
            cin >> p[row * columnSize + col] ;
        }
        
        cout << endl ;
    }
}

void print(int *p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < columnSize; col++)
        {
            // Access the 2D array using the formula (row * columnSize + col)
            cout << setw(5) << p[row * columnSize + col] ;
        }
        
        cout << endl ;
    }
}

/*
==========================================================================
    Dynamic Two-Dimensional Arrays with a Single Pointer
==========================================================================

    int *board;
    board = new int[rows * columns];

    The program allocates one contiguous array of integers. Although the
    data is displayed as rows and columns, board is an int* pointing to
    the first element of a one-dimensional array.

    For example, with rows = 3 and columns = 4, the allocation is:

        board = new int[12];

    The following diagram shows the array after the values 1 through 12
    have been entered. These are example values, not initial values
    assigned by new[].

    Logical view (3 rows x 4 columns):

                       Column
                   0    1    2    3
                +----+----+----+----+
        Row 0   |  1 |  2 |  3 |  4 |
                +----+----+----+----+
        Row 1   |  5 |  6 |  7 |  8 |
                +----+----+----+----+
        Row 2   |  9 | 10 | 11 | 12 |
                +----+----+----+----+

    Actual memory layout (one contiguous block):

        board (int*)
             |
             v
        +----+----+----+----+----+----+----+----+----+----+----+----+
        |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12 |
        +----+----+----+----+----+----+----+----+----+----+----+----+
        | index 0..3   | index 4..7   | index 8..11  |
        |    Row 0     |    Row 1     |    Row 2     |

    Each row occupies columnSize consecutive elements. To locate an
    element at (row, col), the code converts its two coordinates into
    a one-dimensional index:

        index = row * columnSize + col

    Examples when columnSize = 4:

        (row 0, col 0)  ->  0 * 4 + 0 =  0  ->  p[0]
        (row 0, col 3)  ->  0 * 4 + 3 =  3  ->  p[3]
        (row 1, col 0)  ->  1 * 4 + 0 =  4  ->  p[4]
        (row 1, col 2)  ->  1 * 4 + 2 =  6  ->  p[6]
        (row 2, col 3)  ->  2 * 4 + 3 = 11  ->  p[11]

    Array indexing is equivalent to pointer arithmetic:

        p[row * columnSize + col]
        *(p + row * columnSize + col)

    In fill(), the outer loop moves from one row to the next, and the
    inner loop reads each column of that row. The input values are placed
    into the corresponding positions of the contiguous array.

    In print(), the same index calculation retrieves each value.
    setw(5), defined in <iomanip>, sets a minimum output field width
    of five characters. The newline after each row produces the
    two-dimensional display.

    The entire block was allocated with one new[] expression:

        board = new int[rows * columns];

    Therefore, it is released with one matching delete[] expression:

        delete[] board;

    Unlike a double-pointer arrangement (int**), this version does not
    allocate a separate array for each row. A double-pointer version
    may use board[row][col] and requires the individual row arrays and
    the row-pointer array to be released separately. Here all integer
    elements are in one block, accessed with the calculated index.

    rows and columns should be positive, and their product must be a
    valid allocation size. The original code assumes valid input.
==========================================================================
*/
