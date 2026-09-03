//bool logical expression
  
#include <iostream>

using namespace std ;

int main () 
{
    bool legalAge ;
    int age ;

    cout << "Enter age: " ;
    cin >> age ;

    legalAge = (age >= 21) ;

    cout << "legalAge = " << legalAge << endl ;

    return 0 ;
}  