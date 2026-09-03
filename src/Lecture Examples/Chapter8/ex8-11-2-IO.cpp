// Two-Dimensional Arrays and I/O
#include <iostream>
#include <fstream>
#include <iomanip>
    
using namespace std ;

const int NUMBER_OF_ROWS    = 5 ;
const int NUMBER_OF_COLUMNS = 5 ;

void initMatrix(int matrix[][NUMBER_OF_COLUMNS], 
                int NUMBER_OF_ROWS, ifstream& inFile) ;
void printMatrix(int matrix[][NUMBER_OF_COLUMNS], 
                 int NUMBER_OF_ROWS) ;

int main()
{
    ifstream inFile ;  //input file stream variable
    ofstream outFile ; //output file stream variable

    inFile.open("ex8-11-2.txt") ;

    int board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] ;

    initMatrix(board, NUMBER_OF_ROWS, inFile) ;
    cout << endl ;

    printMatrix(board, NUMBER_OF_ROWS) ;
    cout << endl ;

    inFile.close() ;
    outFile.close() ;
    
    return 0 ;
}

// This function takes the input file stream inputFile by reference, 
// reads the matrix elements from the file, and stores them in the 2D array matrix.
void initMatrix(int matrix[][NUMBER_OF_COLUMNS], 
                int numOfRows, 
                ifstream& inFile) // <-- Pass by Reference
{
    int row, col ;

    for (row = 0; row < numOfRows; row++)
    {
        for (col = 0; col < NUMBER_OF_COLUMNS; col++)
            inFile >> matrix[row][col] ;
    }
}

// Two-dimensional arrays can be passed as parameters to a function, 
// and they are passed by value. 
// The base address (that is, the address of the first component of the 
// actual parameter) is passed to the formal parameter. If matrix is 
// the name of a two-dimensional array, then matrix[0][0] is the first 
// component of matrix. When storing a two-dimensional array in the 
// computer’s memory, C11 uses the row order form. That is, the first row 
// is stored first, followed by the second row, followed by the third row, and so on.

// In the case of a one-dimensional array, when declaring it as a formal 
// parameter, we usually omit the size of the array. Because C++ stores 
// two-dimensional arrays in 'row' order form, to compute the address of 
// a component correctly, the compiler must know where one row ends and 
// the next row begins. Thus, when declaring a twodimensional array as 
// a formal parameter, you can omit the size of the first dimension, but 
// not the second; that is, you must specify the number of columns.

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
