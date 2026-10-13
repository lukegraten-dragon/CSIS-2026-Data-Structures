// String Comparison

#include <iostream>
#include <cstring>

using namespace std ;

int main() 
{
    char studentName[21] ; // Array of characters with size of 21
    char myname[16] ; // Essentially a string of characters. But less ideal than using the string data type from cstring
    char yourname[16] ;

    strcpy(myname, "John Robinson") ;
    cout << "myname: " << myname << endl ;
    
    int length = strlen("John Robinson") ; // Gets the length of a string of characters.
    cout << "length of \"John Robinson\": " << length << endl ;

    strcpy(yourname, "Lisa Miller") ;
    cout << "yourname: " << yourname << endl ;

    strcpy(studentName, yourname) ;
    cout << "studentName: " << studentName << endl ;

    // strcmp(s1, s2)
    // Returns a value < 0 if s1 is less than s2
    // Returns 0 if s1 and s2 are the same
    // Returns a value > 0 if s1 is greater than s2
    char s1[] = "Bill" ; // const char* s1 = "Bill" ;
    char s2[] = "Lisa" ; // const char* s2 = "Lisa" ; // L is located 10 characters after B
    cout << "strcmp(s1, s2): " << strcmp(s1, s2) << endl ; // Compares strings alphabetically

    strcpy(yourname, "Kathy Brown") ;
    cout << "yourname: " << yourname << "The first string is less than the second string." << endl ;

    strcpy(myname, "Mark G. Clark") ;
    cout << "myname: " << myname << endl ;

    strcmp(myname, yourname) ;
    cout << "myname: " << myname << endl ;
    cout << "strcmp(myname, yourname): " << strcmp(myname, yourname) << "The first string is greater than the second string." << endl ;
    
    return 0 ;
}