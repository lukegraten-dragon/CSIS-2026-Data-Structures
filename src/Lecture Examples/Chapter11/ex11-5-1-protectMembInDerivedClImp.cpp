#include <iostream>
#include "ex11-5-1-protectMembClass.h"
#include "ex11-5-1-protectMembInDerivedCl.h"
     
using namespace std ; 

void dClass::setData(char ch, double v, int a)
{
    bClass::setData(v) ;

    bCh = ch ; //initialize bCh using the assignment statement
    dA = a ;
}

void dClass::print() const
{
    bClass::print() ;

    cout << "Derived class dA = " << dA << endl ;
}

dClass::dClass(char ch, double u, int x)
   : bClass(ch, u)
{
    dA = x ;
}


