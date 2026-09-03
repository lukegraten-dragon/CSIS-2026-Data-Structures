// Function With Overloading
#include <iostream>
   
using namespace std ; 

void functionXYZ() ;
void functionXYZ(int x, double y) ;
void functionXYZ(double one, int y) ;
void functionXYZ(int x, double y, char ch) ;

int main()
{
    functionXYZ() ;
    functionXYZ(1, 2.19) ;
    functionXYZ(2.19, 1) ;
    functionXYZ(1, 2.19, 'A') ;

    return 0 ;
}

void functionXYZ() { }
void functionXYZ(int x, double y) { }
void functionXYZ(double one, int y) { }
void functionXYZ(int x, double y, char ch) { }
