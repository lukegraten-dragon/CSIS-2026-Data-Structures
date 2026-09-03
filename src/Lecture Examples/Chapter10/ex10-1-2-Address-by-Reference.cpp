// Class address when passing by value and by reference

#include <iostream>  

using namespace std ; 

class addressValue
{

private:
    int int_var ;
} ;

void func_pass_by_value(addressValue a) ;
void func_pass_by_reference(addressValue& b) ;

int main()
{
    addressValue address ;

    cout << "Before passing address: " 
         << &address << endl ;         // address: 0x7ffecb0458d4

    func_pass_by_value(address) ;      // address: 0x7ffecb0458bc
    func_pass_by_reference(address) ;  // address: 0x7ffecb0458d4

    return 0 ;
}

void func_pass_by_value(addressValue a)
{
    cout << "In func_pass_by_value, a: " << &a << endl ;
}

void func_pass_by_reference(addressValue& b)
{
    cout << "func_pass_by_reference, b: " << &b << endl ;
}
