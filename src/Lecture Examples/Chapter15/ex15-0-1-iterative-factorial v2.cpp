// Iterative factorial(n)

#include <iostream>

using namespace std;

/*
IMPORTANT - ITERATIVE FACTORIAL

1. Factorial:
   n! = n * (n-1) * ... * 2 * 1
   By definition, 0! = 1.

2. Iteration:
   This function uses a for loop instead of recursion
   to calculate the factorial.

3. Initialization:
   result starts at 1 because factorial uses multiplication.

4. Loop:
   The loop multiplies result by each integer from 2 to n.

5. Special Cases:
   For n = 0 or n = 1, the loop does not execute,
   and the function correctly returns 1.

6. Limitations:
   Negative input is not validated.
   Large values of n may cause integer overflow.
*/

int factorialIterative(int n)
{
    int result = 1 ;
    for (int i = 2 ; i <= n ; i++)
    {
        result *= i ;
    }
    return result ;
}

int main()
{
    int number ;
    cout << "Enter a number: " ;
    cin >> number ;
    
    cout << "Factorial (Iterative) of " << number << " is: " << factorialIterative(number) << endl ;

    return 0 ;
}
