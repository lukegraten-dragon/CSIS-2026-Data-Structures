// Two-Dimensional Arrays and Enumeration Types
#include <iostream>

using namespace std ;

int main() 
{
    const int NUMBER_OF_ROWS = 6 ;
    const int NUMBER_OF_COLUMNS = 5 ;
    enum carType {GM, FORD, TOYOTA, BMW, NISSAN, VOLVO} ;
    enum colorType {RED, BROWN, BLACK, WHITE, GRAY} ;
    int inStock[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] ;

    // You can also use the enumeration type for array indices.
    inStock[FORD][WHITE] = 15 ;  // inStock[1][3] = 15 ;

    return 0 ;
}