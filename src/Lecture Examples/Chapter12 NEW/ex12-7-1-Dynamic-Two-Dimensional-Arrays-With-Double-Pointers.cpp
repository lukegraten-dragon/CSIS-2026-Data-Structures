// Dynamic Two-Dimensional Arrays with Double Pointers

#include <iostream>                                //Line 1
#include <iomanip>                                 //Line 2

using namespace std ;                              //Line 3

void fill(int **p, int rowSize, int columnSize) ;  //Line 4

void print(int **p, int rowSize, int columnSize) ; //Line 5

int main()                                         //Line 6
{                                                  //Line 7
    int **board ;                                  //Line 8
    int rows ;                                     //Line 9
    int columns ;                                  //Line 10

    cout << "Line 11: Enter the number of rows "
         <<"and columns: " ;                       //Line 11
    
    cin >> rows >> columns ;                       //Line 12
    
    cout << endl ;                                 //Line 13
    
    //Create the rows of board
    board = new int* [rows] ;                      //Line 14

    //Create the columns of board
    for (int row = 0; row < rows; row++)           //Line 15
        board[row] = new int[columns] ;            //Line 16

    //Insert elements into board
    fill(board, rows, columns) ;                   //Line 17
    cout << "Line 18: Board:" << endl ;            //Line 18

    //Output the elements of board
    print(board, rows, columns) ;                  //Line 19

    return 0 ;                                     //Line 20
}                                                  //Line 21

void fill(int **p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        cout << "Enter " << columnSize << " number(s)"
             << " for row number " << row << ": " ;
        
        for (int col = 0; col < columnSize; col++)
            cin >> p[row][col] ;
        
        cout << endl ;
    }
}

void print(int **p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < columnSize; col++)
            cout << setw(5) << p[row][col] ;
        
        cout << endl ;
    }
}

/*
==========================================================================
    Dynamic Two-Dimensional Arrays with Double Pointers
==========================================================================
    A two-dimensional dynamic array is created with a pointer to pointer:

        int **board;

    The number of rows and columns is read at run time. The allocation
    takes place in two steps.

        board = new int*[rows];

    This allocates an array of 'rows' pointers. Each element board[row]
    has type int* and will hold the address of a separate row of integers.
    At this point, the integer rows themselves have not been allocated.

        for (int row = 0; row < rows; row++)
            board[row] = new int[columns];

    This allocates 'columns' integers for each row and stores the address
    of the first integer in board[row].

    For example, if rows = 3 and columns = 4, the memory can be
    represented as follows:

                board (int**)
                     |
                     v
              +----------------+
    board[0]  |  pointer       | ------> +------+------+------+------+
              +----------------+         | [0]  | [1]  | [2]  | [3]  |
    board[1]  |  pointer       | ---+    +------+------+------+------+
              +----------------+    |
    board[2]  |  pointer       | -+ |    +------+------+------+------+
              +----------------+  | +--> | [0]  | [1]  | [2]  | [3]  |
                                  |      +------+------+------+------+
                                  |
                                  |      +------+------+------+------+
                                  +----> | [0]  | [1]  | [2]  | [3]  |
                                         +------+------+------+------+

    Each row is a separate dynamically allocated int array. The integers
    within one row occupy consecutive locations, but different rows are
    not necessarily adjacent to one another in memory.

    The expression board[row][col] selects one integer. For example,
    the following values could be entered through fill():

                           col 0   col 1   col 2   col 3
                 row 0  |    10      20      30      40
                 row 1  |    50      60      70      80
                 row 2  |    90     100     110     120

        board[0][0] = 10
        board[1][2] = 70
        board[2][3] = 120

    Array indexing is based on pointer arithmetic:

        board[row][col]  ==  *(*(board + row) + col)

    First, board + row locates the pointer for the selected row.
    Dereferencing it gives the address of that row's first integer.
    Adding col and dereferencing again accesses the selected integer.

    The functions fill() and print() accept the same address through an
    int** parameter named p:

        fill(board, rows, columns);
        print(board, rows, columns);

    The pointer p is passed by value, but p[row][col] still refers to
    the original dynamically allocated integer. Thus fill() can change
    the elements and print() can read those same elements. The outer
    loop selects rows and the inner loop selects columns. In print(),
    setw(5) specifies a minimum field width of five characters for
    each printed integer.

    The program allocates memory using new[] but does not explicitly
    release it. After the last use of board, the corresponding release
    operations would be:

        for (int row = 0; row < rows; row++)
            delete[] board[row];

        delete[] board;

    The individual integer rows are released first. The array of row
    pointers is released afterward; deleting board first would discard
    the addresses needed to free the individual rows.

    The input dimensions should also be checked before allocation to
    ensure that rows and columns are positive.
*/
