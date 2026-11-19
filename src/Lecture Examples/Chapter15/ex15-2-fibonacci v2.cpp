/*
ITERATIVE FIBONACCI - COMPLETE COMPARISON PROGRAM (COMMENT ONLY)

The executable code below this comment is the original RECURSIVE version.
This complete iterative version is shown for side-by-side study.
It is NOT compiled while inside this comment block.

#include <iostream>
using namespace std;

// Find the nth Fibonacci number with a loop (no recursive calls).
int fibonacciIterative(int n)
{
    // Base cases: F(0) = 0 and F(1) = 1.
    if (n <= 1)
        return n;

    int previous = 0; // F(0)
    int current = 1;  // F(1)

    for (int i = 2; i <= n; i++)
    {
        int next = previous + current; // Calculate F(i).
        previous = current;            // Shift the two values forward.
        current = next;
    }

    return current;
}

int main()
{
    int number;
    cout << "Enter the position of the Fibonacci number you want: ";

    if (!(cin >> number))
    {
        cerr << "Invalid input. Please enter an integer." << endl;
        return 1;
    }

    if (number < 0 || number > 46)
    {
        cerr << "Please enter a position between 0 and 46." << endl;
        return 1;
    }

    int result = fibonacciIterative(number);
    cout << "Fibonacci number at position " << number
         << " is: " << result << endl;

    return 0;
}

*/

// Fibonacci number

#include <iostream>

using namespace std ;

// Recursive function to find the nth Fibonacci number
int fibonacci(int n)
{
    // Base cases: first two Fibonacci numbers
    if (n == 0)
    {
        return 0 ;
    }
    else if (n == 1)
    {
        return 1 ;
    }

    // Recursive case: sum of the two previous Fibonacci numbers
    return fibonacci(n - 1) + fibonacci(n - 2) ;
}

int main()
{
    int number ;
    cout << "Enter the position of the Fibonacci number you want: " ;
    cin >> number ;
    
    int result = fibonacci(number) ;
    cout << "Fibonacci number at position " << number << " is: " << result << endl ;

    return 0 ;
}

/*
Explanation of the Program

1. Base Cases:
  - fibonacci(0) = 0
  - fibonacci(1) = 1
These are the first two numbers in the Fibonacci sequence, so they are returned directly.

2. Recursive Case:
  - For any other position n, the function calls itself twice to calculate 
    fibonacci(n - 1) and fibonacci(n - 2).
  - The function returns the sum of these two previous Fibonacci numbers, following 
    the Fibonacci sequence rule: F(n) = F(n-1) + F(n-2).
*/

/*
PERFORMANCE COMPARISON - RECURSIVE VS. ITERATIVE FIBONACCI

1. Why the recursive approach repeats work:
   - Every call with n >= 2 makes TWO calls:
         fibonacci(n - 1) and fibonacci(n - 2).
   - Different branches recalculate the same values.
     For example, while finding fibonacci(5), fibonacci(3) and
     fibonacci(2) are evaluated more than once.

2. Time complexity:
   - Naive recursion (this executable program): O(2^n) upper bound;
     more precisely, Theta(phi^n), phi approximately 1.618.
   - Iteration (reference function above): O(n).
     It computes the next value only once per loop iteration.

3. Function calls vs. loop iterations:
   n        Recursive calls       Iterative calls     Iterative loop iterations
   0                    1                     1                  0
   1                    1                     1                  0
   5                   15                     1                  4
   10                 177                     1                  9
   20              21,891                     1                 19
   30           2,692,537                     1                 29

   - Recursive calls count EVERY invocation, including base cases.
     The count follows C(0) = C(1) = 1 and
       C(n) = 1 + C(n - 1) + C(n - 2).
   - The iterative function is called once. Its for loop runs n - 1
     times for n >= 2, and zero times for n = 0 or n = 1.
   - These are function-call / iteration counts, not CPU timings.

4. Space complexity:
   - Recursion: O(n) additional call-stack space (maximum depth O(n)).
   - Iteration: O(1) additional space (a fixed number of variables).

5. Improving recursive performance:
   - Memoization stores already calculated Fibonacci values,
     reducing time to O(n), with O(n) extra space.
   - Iteration also runs in O(n) time but needs only O(1) extra space.

6. Input limitations:
   - This recursive program does not validate negative input;
     negative n never reaches either base case.
   - For a typical 32-bit signed int, F(46) fits but F(47) does not.
     Integer overflow affects BOTH recursive and iterative methods.
*/
