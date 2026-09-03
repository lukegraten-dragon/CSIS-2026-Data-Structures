//Example: clear, empty, erase, length, and size functions
  
#include <iostream>                                    //Line 1
#include <string>                                      //Line 2

using namespace std ;                                  //Line 3

int main()                                             //Line 4
{                                                      //Line 5
    string firstName = "Elizabeth" ;                   //Line 6
    string name = firstName + " Jones" ;               //Line 7
    string str1 = "It is sunny.";                      //Line 8
    string str2 = "" ;                                 //Line 9
    string str3 = "computer science" ;                 //Line 10
    string str4 = "C++ programming." ;                 //Line 11
    string str5 = firstName + " is taking " + str4 ;   //Line 12

	// An unsigned integer (data) type
    string::size_type len ;                            //Line 13

    cout << "Line 14: str3: " << str3 << endl ;        //Line 14
    str3.clear() ;                                     //Line 15
    cout << "Line 16: After clear, str3: " << str3 
         << endl ;                                     //Line 16

    cout << "Line 17: str1.empty(): " << str1.empty()
         << endl ;                                     //Line 17
    cout << "Line 18: str2.empty(): " << str2.empty()
         << endl ;                                     //Line 18

    cout << "Line 19: str4: " << str4 << endl ;        //Line 19
    str4.erase(11, 4) ;                                //Line 20

	// Deletes n characters from strVar starting at position pos.
    cout << "Line 21: After erase(11, 4), str4: "
         << str4 << endl ;                             //Line 21

	// Notice that this program uses the static cast operator to output 
	// the value returned by the function length. 
	// This is because the function length returns a value of the type 
	// string::size_type. 
	// Without the cast operator, some compilers might give the following 
	// warning message:
	// conversion from 'size_t' to 'unsigned int', possible loss of data
    cout << "Line 22: Length of \"" << firstName << "\" = " 
         << static_cast<unsigned int> (firstName.length())
		 << endl
		 << firstName.length()
         << endl ;                                     //Line 22
    cout << "Line 23: Length of \"" << name << "\" = " 
         << static_cast<unsigned int> (name.length())
		 << endl
		 << name.length()
         << endl ;                                     //Line 23  	
    cout << "Line 24: Length of \"" << str1 << "\" = " 
         << static_cast<unsigned int> (str1.length())
		 << endl
		 << str1.length()
         << endl ;                                     //Line 24
    cout << "Line 25: Size of \"" << str5 << "\" = " 
         << static_cast<unsigned int> (str5.size()) 
         << endl
		 << str5.length()
		 << endl ;                                     //Line 25

    len = name.length() ;                              //Line 26
    cout << "Line 27: len = " 
         << static_cast<unsigned int> (len) << endl ;  //Line 27

    return 0 ;                                         //Line 28
}                                                      //Line 29


