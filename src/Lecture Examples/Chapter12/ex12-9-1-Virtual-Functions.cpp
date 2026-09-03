// Virtual Functions

/*
So, during program execution, how does C++ correct this problem of making the call 
to the appropriate function? 
    
C++ corrects this problem by providing the mechanism of "virtual functions". 
The binding of virtual functions occurs at program execution time, not at compile time. 
This kind of binding is called "run-time binding", late binding, or dynamic binding. 
More formally, in run-time binding, the compiler does not generate the code to call 
a specific function. Instead, it generates enough information to enable the run-time 
system to generate the specific code for the appropriate function call. 
Run-time binding is also known as "dynamic binding".

In C++, virtual functions are declared using the reserved word virtual. 
Let us redefine the previous classes using this feature.

*** Note that we need to declare a virtual function only in the base class.
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

void callPrint(petType& p)
{
    p.print() ; // <-- petType's print() or dogType's print()?
}

int main()
{
    petType pet("Lucky") ;                    //Line 3
    dogType dog("Tommy", "German Shepherd") ; //Line 4

    pet.print() ;                             //Line 5
    cout << endl ;                            //Line 6
    
    dog.print() ;                             //Line 7
    cout << "*** Calling the function callPrint ***"
        << endl ;                             //Line 8
    
    callPrint(pet) ;                          //Line 9
    cout << endl ;                            //Line 10
    
    callPrint(dog) ;                          //Line 11
    cout << endl ;                            //Line 12

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


