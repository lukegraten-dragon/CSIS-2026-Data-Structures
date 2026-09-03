// String Comparison

#include <iostream>
#include <cstring>

using namespace std ;

int main() 
{
    char studentName[21] ;
    char myname[16] ;
    char yourname[16] ;

    strcpy(myname, "John Robinson") ;
    cout << "myname: " << myname << endl ;
    
    int length = strlen("John Robinson") ;
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
    char s2[] = "Lisa" ; // const char* s2 = "Lisa" ;
    cout << "strcmp(s1, s2): " << strcmp(s1, s2) << endl ;

    strcpy(yourname, "Kathy Brown") ;
    cout << "yourname: " << yourname << endl ;

    strcpy(myname, "Mark G. Clark") ;
    cout << "myname: " << myname << endl ;

    strcmp(myname, yourname) ;
    cout << "myname: " << myname << endl ;
    cout << "strcmp(myname, yourname): " << strcmp(myname, yourname) << endl ;
    
    return 0 ;
}