// Program: Roll dice
//
// we write a function that rolls a pair of dice until the sum 
// of the numbers rolled is a specific number. We also want to know
// the number of times the dice are rolled to get the desired sum.

#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std ;

int rollDice(int num) ;
 
int main()
{
    cout << "The number of times the dice are rolled to "
         << "get the sum 10 = " << rollDice(10) << endl ;
    cout << "The number of times the dice are rolled to "
         << "get the sum 6 = " << rollDice(6) << endl ;

    return 0 ;
}

int rollDice(int num)
{ 
    int die1 ;
    int die2 ;
    int sum ;
    int rollCount = 0 ;

    srand(time(0)) ;

    do
    {
        die1 = rand() % 6 + 1 ;
        die2 = rand() % 6 + 1 ;
        sum = die1 + die2 ;
        rollCount++ ;
    }
    while (sum != num) ;

    return rollCount ;
}
