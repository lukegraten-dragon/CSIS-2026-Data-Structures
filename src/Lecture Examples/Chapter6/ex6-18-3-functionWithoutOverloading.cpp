// Function Without Overloading
#include <iostream>
   
using namespace std ; 

void functionOne(int x) ;
void functionTwo(int x, double y) ;
void functionThree(double y, int x) ;
int  functionFour(char ch, int x, double y) ;
int  functionFive(char ch, int x, string name) ;

int main()
{
    functionOne(1) ;
	functionTwo(1, 2.19) ;
    functionThree(2.19, 1) ;
    functionFour('A', 1, 2.19) ;
    functionFive('A', 1, "Hello") ;

    return 0 ;
}

void functionOne(int x) { }
void functionTwo(int x, double y) { }
void functionThree(double y, int x) { }
int  functionFour(char ch, int x, double y) { return x ; }
int  functionFive(char ch, int x, string name) { return x ; }