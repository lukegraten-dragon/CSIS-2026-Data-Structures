//Program to illustrate how to use the operators new and delete.

#include <iostream>                                   //Line 1
#include <iomanip>                                    //Line 2

using namespace std ;                                 //Line 3

const double PI = 3.1416 ;                            //Line 4

int main()                                            //Line 5
{                                                     //Line 6

    double *radiusPtr ;                               //Line 7

    cout << fixed << showpoint << setprecision(2) ;   //Line 8
    
    radiusPtr = new double ;                          //Line 9
    
    cout << "Line 10: Enter the radius: " ;           //Line 10
    cin >> *radiusPtr ;                               //Line 11
    cout << endl ;                                    //Line 12
    
    cout << "Line 13: Radius = " << *radiusPtr
         << ", area = " << PI * (*radiusPtr) * (*radiusPtr)
         << endl << endl ;                            //Line 13
    
    cout << "Line 14: Address of radiusPtr: "
         << &radiusPtr << endl ;                      //Line 14
    
    cout << "Line 15: Value stored in radiusPtr: "
         << radiusPtr << endl ;                       //Line 15
    
    cout << "Line 16: Value stored in the memory "
         << "location to which \n radiusPtr "
         << "is pointing: " << *radiusPtr << endl ;   //Line 16

    delete radiusPtr ;                                //Line 17
    
    cout << "Line 18: After using the delete operator, "
         << "the value stored in the location\n "
         << "to which radiusPtr is pointing: "
         << *radiusPtr << endl ;                      //Line 18
    
    double *lengthPtr = new double ;                  //Line 19
    
    radiusPtr = new double ;                          //Line 20
    
    *radiusPtr = 5.38 ;                               //Line 21
    
    cout << "Line 22: Address of radiusPtr: "
         << &radiusPtr << endl ;                      //Line 22
    
    cout << "Line 23: Value stored in radiusPtr: "
         << radiusPtr << endl ;                       //Line 23
    
    cout << "Line 24: Value stored in the memory "
         << "location to which radiusPtr is pointing: "
         << *radiusPtr << endl ;                      //Line 24
    
    cout << "Line 25: Value stored in lengthPtr: "
         << lengthPtr << endl ;                       //Line 25
    
    return 0 ;                                        //Line 26
}                                                     //Line 27

/*
For the most part, the preceding program is the same as the program in
Example 12-3. However, let us note the following: the statement in Line 9
allocates memory of type double and stores the address of the allocated memory
in radiusPtr. The output of the statement in Line 15 shows that the address of
the allocated memory is 00DE0230. Next the statement in Line 17 deallocates the
memory space to which radiusPtr is pointing. The statement in Line 20 allocates
(another) memory space of type double and stores the address of the allocated
memory space in radiusPtr, and the statement in Line 21 stores 5.38 in the
allocated memory space. The statements in Lines 23 to 25 output the addresses
as shown by the output. (Note that the addresses printed by this program are
machine dependent. When you run this program on your machine, you are likely
to get different values.)
*/
