#include <iostream>

using namespace std ;
 
int main()   
{  
    char ch1, ch2 ;
    int num ;
    
    //Input: A 25
    //cin >> ch1 >> ch2 >> num ;
    //cout << "ch1 = " << ch1 << endl << "ch2 = " 
    //     << ch2 << endl << "num = " << num << endl ;
    
    // When the computer executes this statement, 'A' is stored in ch1, 
    // the blank is skipped by the extraction operator >>, the character '2' 
    // is stored in ch2, and 5 is stored in num. However, what if you 
    // intended to store 'A' in ch1, the blank in ch2, and 25 in  num? 
    // It is clear that you cannot use the extraction operator >> to input this data.
    
    // The get function inputs the very next character, including whitespace characters
    cin.get(ch1) ; 
    cin.get(ch2) ;
    cin >> num ;
    cout << "ch1 = " << ch1 << endl << "ch2 = " 
         << ch2 << endl << "num = " << num << endl ;


    return 0 ;
}