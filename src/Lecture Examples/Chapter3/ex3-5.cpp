#include <iostream>

using namespace std ;
 
int main()   
{  
    int a, b ;

    // When you want to process only partial data (say, within a line), 
    // you can use the stream function ignore to discard a portion of the input.
    // cin.ignore(intExp, chExp) ;
    // Here, intExp is an integer expression yielding an integer value, 
    // and chExp is a char expression yielding a char value. In fact, the value 
    // of the expression intExp specifies the maximum number of characters to be 
    // ignored in a line.
    // Suppose intExp yields a value of, say 100. This statement says to ignore 
    // the next 100 characters or ignore the input until it encounters the character 
    // specified by chExp, whichever comes first.
    // cin.ignore(100, '\n') ;
    // When this statement executes, it ignores either the next 100 characters or 
    // all characters until the newline character is found, whichever comes first.

    //Input
    //25 67 89 43 72 
    //12 78 34
    cin >> a ;
    cin.ignore(100, '\n') ;
    cin >> b ;
    cout << "a = " << a << endl << "b = " << b << endl ;

    return 0 ;
}