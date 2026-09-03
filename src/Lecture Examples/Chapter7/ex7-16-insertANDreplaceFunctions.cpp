//Example: insert and replace functions

#include <iostream>                                      //Line 1
#include <string>                                        //Line 2
 
using namespace std ;                                    //Line 3

int main()                                               //Line 4
{                                                        //Line 5
    string firstString = "Cloudy and warm." ;            //Line 6
    string secondString = "Hello there" ;                //Line 7
    string thirdString = "Henry is in programming I." ;  //Line 8
    string str1 = " very " ;                             //Line 9
    string str2 = "Lisa" ;                               //Line 10

    cout << "Line 11: firstString = " << firstString
         << endl ;                                       //Line 11
    firstString.insert(10, str1) ;                       //Line 12
    cout << "Line 13: After insert; firstString = "
         << firstString << endl ;                        //Line 13

    cout << "Line 14: secondString = " << secondString
         << endl ;                                       //Line 14
    secondString.insert(11, 5, '!') ;                    //Line 15
    cout << "Line 16: After insert; secondString = "
         << secondString << endl ;                       //Line 16

    cout << "Line 17: thirdString = " << thirdString
         << endl ;                                       //Line 17
    thirdString.replace(0, 5, str2) ;                    //Line 18
    cout << "Line 19: After replace, thirdString = "
         << thirdString << endl ;                        //Line 19

    return 0 ;                                           //Line 20
}                                                        //Line 21
