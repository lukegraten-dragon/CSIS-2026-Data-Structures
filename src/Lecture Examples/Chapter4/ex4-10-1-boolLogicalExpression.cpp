//bool logical expression
  
#include <iostream>

using namespace std ;

int main () 
{
    bool legalAge ;
    int age ;

    cout << "Enter age: " ;
    cin >> age ;

    legalAge = (age >= 21) ; // This expression resolves to 0 or 1 (because boolean expressions return 0 for false, and 1 for true)

    cout << "legalAge = " << legalAge << endl ;

    return 0 ;
}  