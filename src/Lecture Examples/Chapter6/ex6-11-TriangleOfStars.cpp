//Program: Print a triangle of stars
 
#include <iostream>                                      //Line 1

using namespace std ;                                    //Line 2
  
void printStars(int blanks, int starsInLine) ;           //Line 3

int main()                                               //Line 4
{                                                        //Line 5
    int noOfLines ;  //var to store the number of lines    Line 6
    int counter ;    //for loop control variable           Line 7
    int noOfBlanks ; //var to store the number of blanks   Line 8

    cout << "Enter the number of star lines (1 to 20) "
         << "to be printed: " ;                          //Line 9
    cin >> noOfLines ;                                   //Line 10

    while (noOfLines < 0 || noOfLines > 20)              //Line 11
    {                                                    //Line 12
        cout << "Enter the number of star lines "
             << "(1 to 20) to be printed: " ;            //Line 13
        cin  >>  noOfLines;                              //Line 14
    }                                                    //Line 15

    cout << endl << endl ;                               //Line 16
    noOfBlanks = 30 ;                                    //Line 17

    for (counter = 1; counter <= noOfLines; counter++)   //Line 18
    {                                                    //Line 19
        printStars(noOfBlanks, counter) ;                //Line 20
        noOfBlanks-- ;                                   //Line 21
    }                                                    //Line 22

    return 0 ;                                           //Line 23
}                                                        //Line 24

void printStars(int blanks, int starsInLine)             //Line 25
{                                                        //Line 26
    int count ;                                          //Line 27

    for (count = 1; count <= blanks; count++)            //Line 28
        cout << ' ' ;                                    //Line 29

    for (count = 1; count <= starsInLine; count++)       //Line 30
        cout << " *" ;                                   //Line 31
    cout << endl ;                                       //Line 32
}                                                        //Line 33

