// Arrays of Strings
#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
    int length = 3 ;
    // Suppose that the largest string (for example, name) in your list 
    // is 16 characters long and your list has 100 strings. You can declare 
    // a two-dimensional array of characters of 100 rows and 16 columns.
    //char list[100][16] ;
    char list[length][16] ;

    strcpy(list[1], "Snow White") ;

    // Suppose that you want to read and store data in list and that there 
    // is one entry per line. The following for loop accomplishes this task:
    for (int j = 0; j < length; j++)
    {
        cin.getline(list[j], 16) ;
    }

    // The following for loop outputs the string in each row:
    for (int j = 0; j < length; j++)
    {
        cout << list[j] << endl ;
    }

    return 0 ;
}