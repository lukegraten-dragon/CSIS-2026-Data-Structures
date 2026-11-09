/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 08 Part 3
// Date Modified: 11-09-2026
// AI Models Used: No AI Used
//
/******************************************************/

#include <iostream>
using namespace std ;

// Declare template classes
template <class T>
class Storage
{
    public:
        // Helper Functions
        void setValue(T value) {storedValue = value ; }
        T getValue() const { return storedValue ; }
        void printValue() const {cout << "Stored Value: " << storedValue << '\n' ; }
        string isEqual(T value) const {return (value == storedValue) ? "Yes" : "No" ; }

    private:
        // Store a generic variable
        T storedValue ;
} ;

int main ()
{
    // Create objects
    Storage<int> intObject ;
    Storage<double> doubleObject ;
    Storage<string> stringObject ;

    // Sets and display's values for each Storage object
    intObject.setValue(100) ;
    cout << "Stored Value: " << intObject.getValue() << '\n' ; // Use getValue

    doubleObject.setValue(50.5) ;
    doubleObject.printValue(); // Use printValue

    stringObject.setValue("Hello") ;
    stringObject.printValue() ;

    // Check Equality
    cout << '\n' ;
    cout << "Is equal to 100? " << intObject.isEqual(100) << '\n' ;
    cout << "Is equal to 50.5? " << doubleObject.isEqual(50.5) << '\n' ;
    cout << "Is equal to 'Hello'? " << stringObject.isEqual("Hello") << '\n' ;

    cout << "Is equal to 101? " << intObject.isEqual(101) << '\n' ;
    cout << "Is equal to 'HELLO'? " << stringObject.isEqual("HELLO") << '\n' ;

    return 0 ;
}