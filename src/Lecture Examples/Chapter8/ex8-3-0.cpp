// Processing One-Dimensional Arrays

#include <iostream>

using namespace std ;

int main()
{ 
    int n = 3 ;
    int list[n] ; //list is an array of size 100
    
    int i ;

    // for (i = 0; i < n; i++)
    //     cin >> list[i] ;          // process list[i] to input

    for (i = 0; i < n; i++)
        cout << list[i] << " " ;  // process list[i] to output
    cout << endl ;
}