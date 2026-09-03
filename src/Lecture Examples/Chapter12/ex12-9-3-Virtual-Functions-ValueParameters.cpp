// Virtual Functions and Value Parameters

/*
<1>
The preceding examples show that if a formal parameter, say p of a class type, is either a
reference parameter or a pointer and p uses a virtual function of the base class, we can
effectively pass a derived class object as an actual parameter to p.

However, if p is a value parameter, then this mechanism of passing a derived class
object as an actual parameter to p does not work, even if p uses a virtual function.

Recall that if a formal parameter is a value parameter, the value of the actual parameter
is copied into the formal parameter. Therefore, if a formal parameter is of a class
type, the member variables of the actual object are copied into the corresponding
member variables of the formal parameter.
*/

#include <iostream>

using namespace std ;

class petType
{
public:
    virtual void print() const ; // <-- virtual function
    petType(string n = "") ;
private:
    string name ;
} ;

class dogType: public petType
{
public:
    void print() const;
    dogType(string n = "", string b = "") ;
private:
    string breed ;
} ;

/*
<2>
Suppose that we have the above classes—that is, petType and dogType. 
Consider the following function definition:
*/
void callPrint(petType p) //p is a value parameter
{
    p.print() ; // <-- petType's print() or dogType's print()?
}

int main()
{
    petType pet("Lucky") ;                           //Line 3
    dogType dog("Tommy", "German Shepherd") ;        //Line 4

    pet.print() ;                                    //Line 5
    cout << endl ;                                   //Line 6
    
    dog.print() ;                                    //Line 7
    cout << "*** Calling the function callPrint ***"
         << endl ;                                   //Line 8
    
    callPrint(pet) ;                                 //Line 9
    cout << endl ;                                   //Line 10
    
    callPrint(dog) ;                                 //Line 11
    cout << endl ;                                   //Line 12

    /*
    <3>
    Look closely at the output of the statements in Lines 9 and 11 (the last two lines of output).
    In Line 11, because the formal parameter p is a value parameter, the member variables
    of dog are copied into the corresponding member variables of p. However, because
    p is an object of base type petType, it has only the one member variable name. Consequently,
    only the member variable name of dog is copied into the member variable name
    of p. Moreover, the statement p.print(); in the function callPrint executes the function
    print of the base class petType, not of the derived class dogType. Therefore,
    the last line of the output shows only the value of name (the member variable of dog).
    */

    return 0 ;
}

void petType::print() const
{
    cout << "Name: " << name ;
}

petType::petType(string n)
{
    name = n ;
}

void dogType::print() const
{
    petType::print() ;
    cout << ", Breed: " << breed << endl ;
}

dogType:: dogType(string n, string b): petType(n)
{
    breed = b ;
}
