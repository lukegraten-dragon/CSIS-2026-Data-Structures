//**********************************************************
// Program: Telephone Digits
// This is an example of a sentinel-controlled loop. This  
// program converts uppercase letters to their corresponding
// telephone digits.
//********************************************************** 
   
#include <iostream>                                     //Line 1

using namespace std ;                                   //Line 2

int main()                                              //Line 3
{                                                       //Line 4
    char letter;                                        //Line 5
    int digit, num;                                     //Line 6

    cout << "Program to convert uppercase letters to " 
         << "their corresponding telephone digits."
         << endl ;                                      //Line 8

    cout << "To stop the program enter #." << endl ;    //Line 9

    cout << "Enter an uppercase letter: " ;             //Line 10
    cin >> letter ;                                     //Line 11
    cout << endl ;                                      //Line 12

    while (letter != '#')                               //Line 13
    {                                                   //Line 14
        cout << "Letter: " << letter ;                  //Line 15
        cout << ", Corresponding telephone digit: " ;   //Line 16

        num = static_cast<int>(letter) 
             - static_cast<int>('A') ;                  //Line 17

        if (0 <= num && num < 26)                       //Line 18
        {                                               //Line 19
            digit = (num / 3) + 2 ;                     //Line 20

            if (((num / 3 == 6 ) || (num / 3 == 7))     //Line 21
                  && (num % 3 == 0))                    //Line 22 
                digit = digit - 1 ;                     //Line 23

            if (digit > 9)                              //Line 24
                digit = 9 ;                             //Line 25

            cout << digit << endl ;                     //Line 26
        }                                               //Line 27
        else                                            //Line 28
            cout << "Invalid input." << endl ;          //Line 29

        // if (letter >= 'A' && letter <= 'Z')
        //     switch (letter)
        //     {
        //     case 'A':
        //     case 'B':
        //     case 'C':
        //         cout << 2 << endl ;
        //         break ;
        //     case 'D':
        //     case 'E':
        //     case 'F':
        //         cout << 3 << endl ;
        //         break ;
        //     case 'G':
        //     case 'H':
        //     case 'I':
        //         cout << 4 << endl ;
        //         break ;
        //     case 'J':
        //     case 'K':
        //     case 'L':
        //         cout << 5 << endl ;
        //         break ;
        //     case 'M':
        //     case 'N':
        //     case 'O':
        //         cout << 6 << endl ;
        //         break ;
        //     case 'P':
        //     case 'R':
        //     case 'S':
        //         cout << 7 << endl ;
        //         break ;
        //     case 'T':
        //     case 'U':
        //     case 'V':
        //         cout << 8 << endl ;
        //         break ;   
        //     case 'W':
        //     case 'X':
        //     case 'Y':
        //     case 'Z':
        //         cout << 9 << endl ;
        //         break ;          
        //     }

        cout << "\nEnter another uppercase "
             << "letter to find its corresponding " 
             << "telephone digit." << endl ;            //Line 30
        cout << "To stop the program enter #." 
             << endl ;                                  //Line 31

        cout << "Enter a letter: " ;                    //Line 32
        cin >> letter ;                                 //Line 33
        cout << endl ;                                  //Line 34
    }//end while                                        //Line 35 

    return 0 ;                                          //Line 36
}                                                       //Line 37
