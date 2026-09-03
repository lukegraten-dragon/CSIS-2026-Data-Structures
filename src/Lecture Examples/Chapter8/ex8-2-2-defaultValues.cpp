#include <iostream>
using namespace std; 

int globalInt ;           // Default initialized to 0
float globalFloat ;       // Default initialized to 0.0f
double globalDouble ;     // Default initialized to 0.0
bool globalBool ;         // Default initialized to false
char globalChar ;         // Default initialized to '\0'

int main() {
    int localInt ;
    float localFloat ;
    double localDouble ;
    bool localBool ;
    char localChar ;

    cout << "Global int: " << globalInt << endl ;
    cout << "Global float: " << globalFloat << endl ;
    cout << "Global double: " << globalDouble << endl ;
    cout << "Global bool: " << globalBool << endl ;
    cout << "Global char: '" << globalChar << "'" << endl ;

    cout << "Local int: " << localInt << endl ;
    cout << "Local float: " << localFloat << endl ;
    cout << "Local double: " << localDouble << endl ;
    cout << "Local bool: " << localBool << endl ;
    cout << "Local char: '" << localChar << "'" << endl ;

    return 0 ;
}
