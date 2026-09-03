// Virtual Functions

/*
The previous discussion also applies when a formal parameter is a pointer to a class,
and a pointer of the derived class is passed as an actual parameter. To illustrate this
feature, suppose we have the preceding classes.
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

void callPrint(petType *p)
{
    p->print() ; // <-- petType's print() or dogType's print()?
}

int main()
{
    petType *q ;                                     //Line 3
    dogType *r ;                                     //Line 4

    q = new petType("Lucky") ;                       //Line 5
    r = new dogType("Tommy", "German Shepherd") ;    //Line 6
    
    q->print() ;                                     //Line 7
    cout << endl ;                                   //Line 8
    
    r->print() ;                                     //Line 9
    cout << "*** Calling the function callPrint ***"
         << endl ;                                   //Line 10
    
    callPrint(q) ;                                   //Line 11
    cout << endl ;                                   //Line 12
    
    callPrint(r) ;                                   //Line 13

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
