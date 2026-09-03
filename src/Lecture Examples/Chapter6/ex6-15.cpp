//Example 6-15: Reference and value parameters.
//Program: Makes you think. 
  
#include <iostream>                                    //Line 1

using namespace std ;                                  //Line 2

void addFirst(int& first, int& second) ;               //Line 3
void doubleFirst(int one, int two) ;                   //Line 4
void squareFirst(int& ref, int val) ;                  //Line 5

int main()                                             //Line 6
{                                                      //Line 7
    int num = 5 ;                                      //Line 8

    cout << "Line 9: Inside main: num = " << num
         << endl ;                                     //Line 9
						
    addFirst(num, num);                                //Line 10
    cout << "Line 11: Inside main after addFirst:"
         << " num = " << num << endl ;                 //Line 11

    doubleFirst(num, num) ;                            //Line 12
    cout << "Line 13: Inside main after "
         << "doubleFirst: num = " << num << endl ;     //Line 13

    squareFirst(num, num) ;                            //Line 14
    cout << "Line 15: Inside main after "
         << "squareFirst: num = " << num << endl ;     //Line 15

    return 0 ;                                         //Line 16
}                                                      //Line 17

void addFirst(int& first, int& second)                 //Line 18
{                                                      //Line 19
    cout << "Line 20: Inside addFirst:  first = " 
         << first << ", second = " << second << endl ; //Line 20

    first = first + 2 ;                                //Line 21

    cout << "Line 22: Inside addFirst:  first = " 
         << first << ", second = " << second << endl ; //Line 22

    second = second * 2 ;                              //Line 23

    cout << "Line 24: Inside addFirst:  first = " 
         << first << ", second = " << second << endl ; //Line 24
}                                                      //Line 25

void doubleFirst(int one, int two)                     //Line 26
{                                                      //Line 27
    cout << "Line 28: Inside doubleFirst:  one = " 
         << one << ", two = " << two << endl ;         //Line 28

    one = one * 2 ;                                    //Line 29

    cout << "Line 30: Inside doubleFirst:  one = " 
         << one << ", two = " << two << endl ;         //Line 30

    two = two + 2 ;                                    //Line 31

    cout << "Line 32: Inside doubleFirst:  one = " 
         << one << ", two = " << two << endl ;         //Line 32
}                                                      //Line 33

void squareFirst(int& ref, int val)                    //Line 34
{                                                      //Line 35
    cout << "Line 36: Inside squareFirst: ref = "
         << ref << ", val = " << val << endl ;         //Line 36

    ref = ref * ref ;                                  //Line 37

    cout << "Line 38: Inside squareFirst: ref = "
         << ref << ", val = " << val << endl ;         //Line 38

    val = val + 2 ;                                    //Line 39

    cout << "Line 40: Inside squareFirst: ref = "
         << ref << ", val = " << val << endl ;         //Line 40
}                                                      //Line 41


