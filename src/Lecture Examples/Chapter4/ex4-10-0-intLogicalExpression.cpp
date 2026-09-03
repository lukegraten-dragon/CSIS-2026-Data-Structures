//int logical expression
  
#include <iostream>

using namespace std ;

int main () 
{
    int legalAge ;
    int age ;

    cout << "Enter age: " ;
    cin >> age ;

    legalAge = (age >= 21) ;

    cout << "legalAge = " << legalAge << endl ;
    
    cout << "!(!36) == " << !(!36) << endl ; // !(!36) = !(0) = 1

    return 0 ;
}  