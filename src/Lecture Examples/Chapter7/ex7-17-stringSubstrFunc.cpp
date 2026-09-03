//Example: substr function

#include <iostream>                                   //Line 1
#include <string>                                     //Line 2
 
using namespace std ;                                 //Line 3
 
int main()                                            //Line 4
{                                                     //Line 5
    string sentence ;                                 //Line 6
    string str ;                                      //Line 7

    sentence = "It is cloudy and warm." ;             //Line 8

    cout << "Line 9: substr(0, 5) in \"" 
         << sentence << "\" = \"" 
         << sentence.substr(0, 5) << "\"" << endl ;   //Line 9
	 
    cout << "Line 10: substr(6, 6) in \"" 
         << sentence << "\" = \"" 
         << sentence.substr(6, 6) << "\"" << endl ;   //Line 10
	 
    cout << "Line 11: substr(6, 16) in \"" 
         << sentence << "\" = " << endl 
         << "         \"" << sentence.substr(6, 16) 
         << "\"" << endl ;                            //Line 11

    cout << "Line 12: substr(17, 10) in \"" 
         << sentence << "\" = \"" 
         << sentence.substr(17, 10) << "\"" << endl ; //Line 12

    cout << "Line 13: substr(3, 6) in \"" 
         << sentence << "\" = \"" 
         << sentence.substr(3, 6) << "\"" << endl ;   //Line 13

    str = sentence.substr(0, 8);                      //Line 14
    cout << "Line 15: " << "str = \"" << str  
         << "\"" << endl ;                            //Line 15
	 
    str = sentence.substr(2, 10);                     //Line 16
    cout << "Line 17: " << "str = \"" << str 
         << "\"" << endl ;                            //Line 17
	 
    return 0 ;                                        //Line 18
}                                                     //Line 19
