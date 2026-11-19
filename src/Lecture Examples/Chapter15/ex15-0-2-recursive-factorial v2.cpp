// Recursive factorial(n)

/*
In recursion, a function calls itself to break down the problem into 
smaller subproblems. Each recursive call has a specific purpose 
until it reaches a "base case," which stops further recursive calls 
and initiates the process of "unwinding" the stack of function calls.

  - Base Case: The condition that stops the recursion. Here, the base case 
    is when n ≤ 1, where the function simply returns 1.
  - Recursive Case: If the base case is not met, the function calls itself 
    with n−1, slowly reducing the problem size until it reaches the base case.
*/
#include <iostream>

using namespace std ;

/*
Example: factorial(4)

Recursive Calls (going deeper):
factorial(4)
  -> factorial(3)
  -> factorial(2)
  -> factorial(1)  // Base Case: return 1

Unwinding (returning in reverse order):
factorial(1) returns 1
factorial(2) returns 2 * 1 = 2
factorial(3) returns 3 * 2 = 6
factorial(4) returns 4 * 6 = 24

Important: Recursive calls proceed toward the base case, but the
pending multiplications are completed as the call stack unwinds.
*/
// Function to calculate factorial recursively
int factorial(int n)
{
    if (n <= 1) // Base case: factorial of 0 or 1 is 1
    {
        return 1 ;
    }
    else // Recursive case: n * factorial(n - 1)
    {
        return n * factorial(n - 1) ;
    }
}

int main()
{
    int number ;
    cout << "Enter a number: " ;
    cin >> number ;
    
    cout << "Factorial (Recursive) of " << number << " is: " << factorial(number) << endl ;

    return 0 ;
}

/*
1. Comparison Between Recursive and Iterative Approaches

| Aspect             | Recursive Version                          | Iterative Version                          |
|--------------------|--------------------------------------------|--------------------------------------------|
| Implementation     | Uses function calls, breaking down         | Uses a loop to calculate the factorial     |
|                    | the task into smaller problems             |                                            |
|--------------------|--------------------------------------------|--------------------------------------------|
| Base Case          | Yes, essential for recursion               | No base case needed                        |
|--------------------|--------------------------------------------|--------------------------------------------|
| Memory Usage       | Uses more memory due to call stack         | More memory-efficient, no extra call stack |
|--------------------|--------------------------------------------|--------------------------------------------|
| Performance        | Slower for large `n` due to function calls | Faster due to no overhead from recursion   |
|--------------------|--------------------------------------------|--------------------------------------------|
| Complexity         | Simple to read and write                   | Often considered faster for performance    |
|--------------------|--------------------------------------------|--------------------------------------------|
| Stack Overflow     | Possible with deep recursive calls         | No recursive call-stack buildup            |

Note on overflow:
  - Stack overflow is a recursion-depth concern; iteration does not build
    up recursive call frames.
  - Integer overflow is a separate issue for BOTH approaches when the
    factorial result exceeds the range of int (e.g., 13! for 32-bit int).
  - This example does not validate negative inputs; n < 0 incorrectly returns 1.

2. Which to Choose?
  - Recursive Approach: Generally better for simplicity and readability, especially 
    in small-scale problems where understanding the process is essential.
  - Iterative Approach: Typically preferred for larger values of n due to lower memory 
    use and faster execution.

Each approach has its own strengths, and the choice largely depends on problem constraints 
and program requirements.
*/
