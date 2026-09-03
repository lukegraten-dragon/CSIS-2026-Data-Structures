#include <iostream>
#include <fstream>

using namespace std ;

int main()
{
    ifstream inFile ;  //input file stream variable

    inFile.open("ex5-23.txt") ;

    int sum, counter, num ;

    counter = 0 ;                           //Line 1
    inFile >> num ;                         //Line 2

    while (inFile)                          //Line 3
    {                                       //Line 4
        sum = 0 ;                           //Line 5
        while (num != -999)                 //Line 6
        {                                   //Line 7
            sum = sum + num ;               //Line 8
            inFile >> num ;                 //Line 9
        }                                   //Line 10

        counter++ ;                         //Line 11
        
        cout << "Line " << counter
             << ": Sum = " << sum << endl ; //Line 12
        
        inFile >> num ;                     //Line 13
    }

    inFile.close() ;
    
    return 0 ;
}