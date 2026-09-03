// Two-Dimensional Arrays
// PROCESSING TWO-DIMENSIONAL ARRAYS
// - Initialization
// - Print
// - Input
// - Sum by Row
// - Sum by Column
// - Largest Element in Each Row and Each Column

#include <iostream>                                  //Line 1
#include <iomanip>                                   //Line 2
    
using namespace std ;                                //Line 3

const int NUMBER_OF_ROWS = 6 ;                       //Line 4
const int NUMBER_OF_COLUMNS = 5 ;                    //Line 5

void printMatrix(int matrix[][NUMBER_OF_COLUMNS], 
                 int NUMBER_OF_ROWS) ;               //Line 6
void sumRows(int matrix[][NUMBER_OF_COLUMNS], 
             int NUMBER_OF_ROWS) ;                   //Line 7
void largestInRows(int matrix[][NUMBER_OF_COLUMNS], 
                   int NUMBER_OF_ROWS) ;             //Line 8

int main()                                           //Line 9
{                                                    //Line 10
    int board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] 
                        = {{17, 8, 24, 10, 28},
                           {9, 20, 16, 55, 90},
                           {25, 45, 35, 8, 78},
                           {5, 0, 96, 45, 38},
                           {76, 30, 8, 14, 28},
                           {9, 60, 55, 62, 10}} ;    //Line 11

    printMatrix(board, NUMBER_OF_ROWS) ;             //Line 12
    cout << endl ;                                   //Line 13
    sumRows(board, NUMBER_OF_ROWS) ;                 //Line 14
    cout << endl ;                                   //Line 15
    largestInRows(board, NUMBER_OF_ROWS) ;           //Line 16

    return 0 ;                                       //Line 17
}                                                    //Line 18

void printMatrix(int matrix[][NUMBER_OF_COLUMNS], 
                 int numOfRows)
{
    int row, col ;

    for (row = 0; row < numOfRows; row++)
    {
        for (col = 0; col < NUMBER_OF_COLUMNS; col++)
            cout << setw(5) << matrix[row][col] << " " ;

        cout << endl ;
    }
}

void sumRows(int matrix[][NUMBER_OF_COLUMNS], int numOfRows)
{
    int row, col ;
    int sum ;

    //Sum of each individual row
    for (row = 0; row < numOfRows; row++)
    {
        sum = 0 ;

        for (col = 0; col < NUMBER_OF_COLUMNS; col++)
            sum = sum + matrix[row][col] ;

        cout << "Sum of row " << (row + 1) << " = " << sum
             << endl ;
    }
}

void largestInRows(int matrix[][NUMBER_OF_COLUMNS], 
                   int numOfRows)
{
    int row, col ;
    int largest ;

    //Largest element in each row
    for (row = 0; row < numOfRows; row++)
    {
        largest = matrix[row][0] ; //Assume that the first element
                                   //of the row is the largest.
        for (col = 1; col < NUMBER_OF_COLUMNS; col++)
            if (largest < matrix[row][col])
                largest = matrix[row][col] ;

        cout << "The largest element of row " << (row + 1) 
             << " = " << largest << endl ;
    }
}
