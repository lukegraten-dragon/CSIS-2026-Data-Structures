/*
In the 19th century, a game called the Tower of Hanoi became popular in Europe.
This game represents work that is under way in the temple of Brahma. At the creation
of the universe, priests in the temple of Brahma were supposedly given three diamond
needles, with one needle containing 64 golden disks. Each golden disk is slightly
smaller than the disk below it. The priests’ task is to move all 64 disks from the first
needle to the third needle. The rules for moving the disks are as follows:
    1. Only one disk can be moved at a time.
    2. The removed disk must be placed on one of the needles.
    3. A larger disk cannot be placed on top of a smaller disk.
The priests were told that once they had moved all of the disks from the first needle
to the third needle, the universe would come to an end.
*/
#include <iostream>

using namespace std ;

int moveCount = 0 ; // Global counter for the number of moves

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    // Base case: only one disk to move directly to the destination
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl ;
        moveCount++ ;
        return ;
    }

    // Recursive case: move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination) ;

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl ;
    moveCount++ ;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source) ;
}

int main()
{
    int n ;
    cout << "Enter the number of disks: " ;
    cin >> n ;

    cout << "The sequence of moves for " << n << " disks is: " << endl ;
    towerOfHanoi(n, 'A', 'C', 'B') ; // 'A' is source, 'C' is destination, 'B' is auxiliary

    cout << "\nTotal number of moves: " << moveCount << endl ;

    return 0 ;
}

/*
IMPORTANT - TOWER OF HANOI USING RECURSION

1. Problem and Rules:
   Tower of Hanoi consists of three pegs and n disks of different sizes.
   The goal is to move all disks from source to destination using auxiliary.

   Rules:
   - Move only one disk at a time.
   - Only the top disk of a peg can be moved.
   - A larger disk cannot be placed on a smaller disk.

2. Function Parameters:

   void towerOfHanoi(int n, char source,
                     char destination, char auxiliary)

   n           : Number of disks to move.
   source      : Peg where the disks currently reside.
   destination : Peg where the disks should be moved.
   auxiliary   : Temporary peg used during the process.

   IMPORTANT:
   The roles of source, destination, and auxiliary change between
   recursive calls. They are roles, not permanently assigned pegs.

3. Base Case:

   if (n == 1)

   When only one disk remains, move it directly from source to destination.
   No further recursive calls are needed.

4. Recursive Case - Three Steps:

   To move n disks from source to destination:

   STEP 1: Move the top n-1 disks from source to auxiliary,
           using destination as the temporary peg.

           towerOfHanoi(n-1, source, auxiliary, destination);

   STEP 2: Move the largest remaining disk (disk n)
           directly from source to destination.

   STEP 3: Move the n-1 disks from auxiliary to destination,
           using source as the temporary peg.

           towerOfHanoi(n-1, auxiliary, destination, source);

   IMPORTANT:
   STEP 1 must finish before STEP 2 can run.
   STEP 3 begins only after the largest disk has been moved.

5. Example - towerOfHanoi(3, 'A', 'C', 'B'):

   A = Source
   B = Auxiliary
   C = Destination

   Recursive Call Tree and Execution Order:

   towerOfHanoi(3, A, C, B)
   │
   ├── towerOfHanoi(2, A, B, C)
   │   ├── towerOfHanoi(1, A, C, B) → Disk 1: A → C
   │   ├── Move Disk 2: A → B
   │   └── towerOfHanoi(1, C, B, A) → Disk 1: C → B
   │
   ├── Move Disk 3: A → C
   │
   └── towerOfHanoi(2, B, C, A)
       ├── towerOfHanoi(1, B, A, C) → Disk 1: B → A
       ├── Move Disk 2: B → C
       └── towerOfHanoi(1, A, C, B) → Disk 1: A → C

   Actual Sequence of Moves:

   Move 1: Disk 1, A → C
   Move 2: Disk 2, A → B
   Move 3: Disk 1, C → B
   Move 4: Disk 3, A → C
   Move 5: Disk 1, B → A
   Move 6: Disk 2, B → C
   Move 7: Disk 1, A → C

   Total number of moves = 7.

   IMPORTANT:
   The first recursive call completes before disk n is moved.
   The second recursive call begins after disk n has been moved.
   Each recursive call has its own parameter values, so the roles
   of the three pegs change accordingly.

6. Recursion and Call Stack:

   Each non-base call makes TWO recursive calls.
   The first call must return before the function moves disk n.
   After moving disk n, the second call is executed.

   Each recursive call has its own local parameter values:
   n, source, destination, and auxiliary.
   When a recursive call finishes, execution resumes in its caller.

7. Performance - Time and Space Complexity:

   a. Number of Moves:
      Let T(n) be the number of disk moves for n disks.

          T(n) = 2*T(n-1) + 1
          T(1) = 1

      Solving the recurrence gives:

          T(n) = 2^n - 1

   b. Exponential Time Complexity:

      Number of disks     Minimum moves
              1                 1
              2                 3
              3                 7
              4                15
              5                31
             10             1,023
             20         1,048,575
             30     1,073,741,823

      Time Complexity: O(2^n)
      Each additional disk approximately doubles the required moves.

   c. Memory Usage:
      Recursive calls use the call stack; maximum recursion depth
      is proportional to n.

      Auxiliary Stack Space Complexity: O(n)

   d. Comparison with Recursive Fibonacci:
      Both algorithms require exponential time in their simple
      recursive forms, but for different reasons.

      Recursive Fibonacci repeatedly calculates identical subproblems;
      memoization or iteration can avoid this unnecessary work.

      Tower of Hanoi requires at least 2^n - 1 physical moves.
      Therefore, exponential work is unavoidable when every move
      must be performed or printed.

8. Global Variable - moveCount:

   moveCount is a global counter shared by all recursive calls.
   It is incremented whenever a disk move is printed.
   Because towerOfHanoi returns void, main() reads moveCount
   to display the total number of moves.

9. Limitations:

   - Input must be a positive integer (n >= 1).
   - The current program does not validate input.
   - If n <= 0, the base case is not reached and recursion continues.
   - Large n produces an enormous amount of output.
   - The int moveCount can overflow for sufficiently large n.

IMPORTANT CONCEPT:

   The central pattern is:

       FIRST RECURSIVE CALL
                |
       MOVE THE LARGEST DISK
                |
       SECOND RECURSIVE CALL

   Understanding this execution order is more important than
   memorizing the code.
*/
