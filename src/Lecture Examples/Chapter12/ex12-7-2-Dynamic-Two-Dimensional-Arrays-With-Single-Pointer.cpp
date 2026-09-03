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
