// This program illustrates how explicit type conversion works.
  
#include <iostream> 

using namespace std ; 

int main() 
{
    cout << "static_cast<int>(7.9) = " << static_cast<int>(7.9) // 7
         << endl ;
    cout << "static_cast<int>(3.3) = " << static_cast<int>(3.3)  // 3
         << endl ;
    cout << "static_cast<double>(25) = " << static_cast<double>(25) // 25.0 internally, but 25 displayed
         << endl ;
    cout << "static_cast<double>(5 + 3) = "
         << static_cast<double>(5 + 3)  // 8.0 internally, but 8 displayed
         << endl ;
    cout << "static_cast<double>(15) / 2 = " 
         << static_cast<double>(15) / 2  // 7.5 since c++ promotes mixed operators to the highest precison type (e.g. double is more precise than int)
         << endl ;
    cout << "static_cast<double>(15 / 2) = "
         << static_cast<double>(15 / 2)  // 7.0 internally, but 7 displayed
         << endl ;
    cout << "static_cast<int>(7.8 + static_cast<double>(15) / 2) = "
         << static_cast<int>(7.8 + static_cast<double>(15) / 2) // 15
         << endl ;
    cout << "static_cast<int>(7.8 + static_cast<double>(15 / 2)) = "
         << static_cast<int>(7.8 + static_cast<double>(15 / 2)) // 14 because static_cast<double> has integer division, which truncates to 7 and then is 7.0 when casted to double
         << endl ;
    
    return 0 ;
}