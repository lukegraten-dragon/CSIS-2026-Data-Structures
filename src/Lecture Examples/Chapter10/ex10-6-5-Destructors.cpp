// Destructors

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

    clockType() {}             // default constructor
    clockType(int, int, int) ; // constructor with parameters

    // Like constructors, destructors are also functions. Moreover, 
    // like constructors, a destructor does not have a type. 
    // That is, it is neither a value-returning function nor a
    // void function. However, a class can have only one destructor, 
    // and the destructor has no parameters. The name of a destructor 
    // is the tilde character (~), followed by the name of the class. 
    // For example, the name of the destructor for the class clockType is:
    ~clockType() ;
    // The destructor automatically executes when the class object 
    // goes out of scope. The use of destructors is discussed in 
    // subsequent chapters.

private:
    int hr  = 0 ;
    int min = 0 ;
    int sec = 0 ;
} ;

int main()
{

    return 0 ;
}