#include <iostream>
#include <fstream>

using namespace std ;

int main()
{
    ifstream inFile ;  //input file stream variable
    ofstream outFile ; //output file stream variable

    inFile.open("ex5-23.txt") ;

    int sum, counter, num ;

    counter = 0 ;                           //Line 1
    while (counter < 5)                     //Line 2
    {                                       //Line 3
        sum = 0 ;                           //Line 4

        inFile >> num ;                     //Line 5
        
        while (num != -999)                 //Line 6
        {                                   //Line 7
            sum = sum + num ;               //Line 8
            inFile >> num ;                 //Line 9
        }                                   //Line 10
        
        cout << "Line " << counter
             << ": Sum = " << sum << endl ; //Line 11
        
        counter++ ;                         //Line 12
    }

    inFile.close() ;

    return 0 ;
}