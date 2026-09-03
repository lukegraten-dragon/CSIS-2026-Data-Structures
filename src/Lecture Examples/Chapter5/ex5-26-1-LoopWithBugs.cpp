// The objective is to find the sum of the numbers in each line. 
// For each line, output the numbers together with their sum.

#include <iostream>
#include <fstream>

using namespace std ;
 
int main()
{
    ifstream infile ;

    int i ;      
    int j ;
    int sum ;
    int num ;

    infile.open("ex5-26-LoopWithBugsData.txt") ;

    for (i = 1; i <= 4; i++)
    {
        sum = 0 ;

        for (j = 1; j <= 4; j++)
        {
            infile >> num ;
            cout << num << " " ;
            sum = sum + num ;
        }
        
        cout << "sum = " << sum << endl ;
    }

    // The sample run shows that there is a bug in the program because 
    // the file contains three lines of input and the output contains 
    // four lines. Also, the number 56 in the last line repeats four times. 
    // Clearly, there is a bug in the program and we must fix the code.

    return 0 ;
 }
