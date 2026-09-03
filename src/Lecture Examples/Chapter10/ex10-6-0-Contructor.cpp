// *** Constructors ***

// In C++, a constructor is a special type of member function 
// that is automatically called when an object of a class is created. 
// Constructors are primarily used to initialize objects. They have the 
// same name as the class and do not have a return type, not even void.

// To guarantee that the member variables of a class are initialized, 
// you use constructors. There are two types of constructors: with 
// parameters and without parameters. The constructor without parameters 
// is called the default constructor.

// Constructors have the following properties:
// - The name of a constructor is the same as the name of the class.
// - A constructor is a function and it has no type. That is, it is neither a
//   value-returning function nor a void function.
// - A class can have more than one constructor. However, all constructors
//   of a class have the same name.
// - If a class has more than one constructor, the constructors must have
//   different formal parameter lists. That is, either they have a different
//   number of formal parameters or, if the number of formal parameters is
//   the same, then the data type of the formal parameters, in the order you
//   list, must differ in at least one position. In other words, like function
//   overloading, a constructor’s name is overloaded.
// - Constructors execute automatically when a class object is declared and
//   enters its scope. Because they have no types, they cannot be called like
//   other functions.
// - Which constructor executes depends on the types of values passed to
//   the class object when the class object is declared.
#include <iostream>  

using namespace std ; 

class clockType
{
public:
    void setTime(int, int, int) ;
    void getTime(int&, int&, int&) const ;
    void printTime() const ;
    void incrementSeconds() ;
    void incrementMinutes() ;
    void incrementHours() ;
    bool equalTime(const clockType&) const ;

    clockType() ;              //default constructor
    clockType(int, int, int) ; //constructor with parameters

private:
    int hr ;
    int min ;
    int sec ;
} ;

int main()
{
    // Recall that when a class object is declared, a constructor is 
    // automatically executed. Because a class might have more than 
    // one constructor, including the default constructor, next we 
    // discuss how to invoke a specific constructor.

    clockType clock1 ;              // Invoking the Default Constructor
    clockType clock2(10, 10, 30) ;  // Invoking a Constructor with Parameters

    clock1.printTime() ;
    cout << endl ;
    clock2.printTime() ;
    cout << endl ;

    return 0 ;
}

clockType::clockType() //default constructor
{
    hr = 0 ;
    min = 0 ;
    sec = 0 ;
}

clockType::clockType(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours ;
    else
        hr = 0 ;
    
    if (0 <= minutes && minutes < 60)
        min = minutes ;
    else
        min = 0 ;
    
    if (0 <= seconds && seconds < 60)
        sec = seconds ;
    else
        sec = 0 ;
}
// Alternative definition of clockType(int hours, int minutes, int seconds) using setTime()
// clockType::clockType(int hours, int minutes, int seconds)
// {
//     setTime(hours, minutes, seconds) ;
// }

void clockType::printTime() const
{
    if (hr < 10)
        cout << "0" ;
    cout << hr << ":" ;

    if (min < 10)
        cout << "0" ;
    cout << min << ":" ;

    if (sec < 10)
        cout << "0" ;
    cout << sec ;
}
