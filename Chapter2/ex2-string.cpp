#include <iostream>
#include <string>

using namespace std ;
 
int main()   
{  
    // Create and initialize a string
    string greeting = "Hello, " ;
    string name ;

    // Ask the user for their name
    cout << "Enter your name: " ;
    getline(cin, name) ;  // Read a full line of text into the name variable

    // Concatenate the greeting with the name
    string fullGreeting = greeting + name + "!" ;

    // Output the full greeting
    cout << fullGreeting << endl ;

    // Demonstrate some basic string operations
    cout << "Your name has " << name.length() << " characters." << endl ;
    cout << "The first letter of your name is: " << name[0] << endl ;

    return 0 ;
}