//Example string operations
  
#include <iostream>                                  //Line 1
#include <string>                                    //Line 2

using namespace std ;                                //Line 3

int main()                                           //Line 4
{                                                    //Line 5
    string name = "William Jacob" ;                  //Line 6
    string str1, str2, str3, str4 ;                  //Line 7

    cout << "Line  8: Name = " << name << endl ;     //Line 8

    str1 = "Hello There" ;                           //Line 9
    cout << "Line 10: str1 = " << str1 << endl ;     //Line 10

    str2 = str1 ;                                    //Line 11
    cout << "Line 12: str2 = " << str2 << endl ;     //Line 12

    str1 = "Sunny" ;                                 //Line 13
    str2 = str1 + " Day" ;                           //Line 14
    cout << "Line 15: str2 = " << str2 << endl ;     //Line 15

    str1 = "Hello" ;                                 //Line 16
    str2 = "There" ;                                 //Line 17
    str3 = str1 + " " + str2 ;                       //Line 18
    cout << "Line 19: str3 = " << str3 << endl ;     //Line 19

    str3 = str1 + ' ' + str2 ;                       //Line 20
    cout << "Line 21: str3 = " << str3 << endl ;     //Line 21

    str1 = str1 + " Mickey" ;                        //Line 22
    cout << "Line 23: str1 = " << str1 << endl ;     //Line 23

    str1 = "Hello there" ;                           //Line 24
    cout << "Line 25: str1[6] = " << str1[6]
         << endl ;                                   //Line 25
					
    str1[6] = 'T' ;                                  //Line 26
    cout << "Line 27: str1 = " << str1 << endl ;     //Line 27

     //String input operations
    cout << "Line 28: Enter a string with "
         << "no blanks: ";                           //Line 28
    cin >> str1 ;                                    //Line 29

    char ch ;                                        //Line 30
    cin.get(ch) ;   //Read the newline character;      Line 31
    cout << endl ;                                   //Line 32

    cout << "Line 33: The string you entered = "
         << str1 << endl ;                           //Line 33

    cout << "Line 34: Enter a sentence: " ;          //Line 34
    getline(cin, str2) ;                             //Line 35
    cout << endl ;                                   //Line 36

    cout << "Line 37: The sentence is: " << str2 
         << endl ;                                   //Line 37

    return 0 ;                                       //Line 38
}                                                    //Line 39
