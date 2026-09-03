#include <iostream>

using namespace std ;
 
int main()   
{
    char a ;
    short b ;
    int c ;
    long d ;
    long long e ;
    bool f ;
    float g ;
    double h ;

    // Uses sizeof() to display data type size in bytes
    // On Mac long has 8 bytes allocated. On Windows however, the system allocates
    // 4 bytes to long, the same size as int. long long allocates the same 8 bytes cross-platform

    cout << "Size of char = "<< sizeof(a) <<" bytes \n" ;
    cout << "Size of short = "<< sizeof(b) <<" bytes \n" ;
    cout << "Size of int = "<< sizeof(c) <<" bytes \n" ;
    cout << "Size of long = "<< sizeof(d) <<" bytes\n" ;
    cout << "Size of long long = "<< sizeof(e) <<" bytes\n" ;
    cout << "Size of bool = "<< sizeof(f) <<" bytes \n" ;
    cout << "Size of float = "<< sizeof(g) <<" bytes \n" ;
    cout << "Size of double = "<< sizeof(h) <<" bytes \n" ;

    return 0 ;
}