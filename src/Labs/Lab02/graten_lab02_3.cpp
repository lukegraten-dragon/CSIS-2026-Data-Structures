/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Lab 02 Part 3
// Date Modified: 09-10-2026
//
/******************************************************/

# include <iostream>
using namespace std ;

int main ()
{
    // Read a word and apply cin functions
    // .get extracts a character
    // .putback places an extracted character back into the buffer
    // .peek reads a character without extracting if from the stream
    char inputCh ;

    cout << "Enter a word (at least 3 characters): " ;
    cin.get(inputCh) ;
    cout << '\n' ;
    cout << "First Character: " << inputCh << '\n' ;

    cin.get(inputCh) ;
    cout << '\n' ;
    cout << "Second Character before putback: " << inputCh << '\n' ;
    cin.putback(inputCh) ;

    inputCh = cin.peek() ;
    cout << '\n' ;
    cout << "Character after putback and peek: " << inputCh << '\n' ;

    cin.get(inputCh) ;
    cout << '\n' ;
    cout << "Character after get: " << inputCh << '\n' ;

    return 0 ;
}

/*
Post-Lab Reflection

In this lab section I applied cin.get, .putback, and .peek
functions to extract and read data from and user inputted string.
*/