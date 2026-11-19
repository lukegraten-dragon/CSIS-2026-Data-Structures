#include <iostream>
#include <vector>
#include <cmath>      // For mathematical functions like pow, sqrt, abs
#include <numeric>    // For accumulate, gcd, and lcm

using namespace std ;

int main()
{
    // Using basic math functions from <cmath>
    double base = 5.0, exponent = 3.0 ;
    cout << "Power (" << base << "^" << exponent << "): " << pow(base, exponent) << endl ;

    double number = 16.0 ;
    cout << "Square root of " << number << ": " << sqrt(number) << endl ;

    int negative_number = -42 ;
    cout << "Absolute value of " << negative_number << ": " << abs(negative_number) << endl ;

    // Using STL math functions with vectors
    vector<int> numbers = {1, 2, 3, 4, 5} ;

    // Sum of all elements using accumulate
    int sum = accumulate(numbers.begin(), numbers.end(), 0) ;
    cout << "Sum of all elements in the vector: " << sum << endl ;

    // Product of all elements using accumulate with a custom lambda
    int product = accumulate(numbers.begin(), numbers.end(), 1, [](int a, int b) { return a * b ; }) ;
    cout << "Product of all elements in the vector: " << product << endl ;

    // Find the Greatest Common Divisor (GCD) of two numbers
    int num1 = 36, num2 = 60 ;
    cout << "GCD of " << num1 << " and " << num2 << ": " << gcd(num1, num2) << endl ;

    // Find the Least Common Multiple (LCM) of two numbers
    cout << "LCM of " << num1 << " and " << num2 << ": " << lcm(num1, num2) << endl ;

    // Using more math functions
    double angle = 45.0 ; // in degrees
    double radians = angle * M_PI / 180.0 ; // Convert to radians
    cout << "Sin(" << angle << " degrees): " << sin(radians) << endl ;
    cout << "Cos(" << angle << " degrees): " << cos(radians) << endl ;
    cout << "Tan(" << angle << " degrees): " << tan(radians) << endl ;

    return 0 ;
}
