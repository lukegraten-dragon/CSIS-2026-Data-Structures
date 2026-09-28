/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Assignment 04
// Date Modified: 09-28-2026
//
/******************************************************/

# include <iostream>
# include <cmath>
# include <string>
using namespace std ;

/******************************************************/
// FUNCTIONS
/******************************************************/

double add (double numOne, double numTwo)
{
    return (numOne + numTwo) ;
}

double subtract (double numOne, double numTwo)
{
    return (numOne - numTwo) ;
}

double multiply (double numOne, double numTwo)
{
    return (numOne * numTwo) ;
}

double divide (double numerator, double denominator)
{
    if (denominator != 0)
    {
        return (numerator / denominator) ;
    }
    else 
    {
        return 0 ;
    }
        
}

double exponentiate (double numOne, double exp)
{
    if (exp >= 0)
    {
        return pow(numOne, exp) ;
    }
    else
    {
        return (1 / pow(numOne, -(exp))) ;
    }
    
}

double ask_num(string header)
{
    double numAssign ;

    cout << header ;
    cin >> numAssign ;
    cout << '\n' ;
    cin.clear() ;
    cin.ignore(numeric_limits<streamsize>::max(), '\n') ;

    return numAssign ;
}

/******************************************************/
// BEGIN MAIN HERE
/******************************************************/

int main()
{
    int userChoice ; // User choice for menu
    bool tryAgain = true ; // Whether to try program again.
    double num1 ; // Numbers user chooses for operations
    double num2 ;

    do {
        // Reset User choice
        userChoice = 0 ;
        // Menu Interface
        do
        {
            cout << "[ Simple Calculator Menu ]\n"
                << "1. Addition\n"
                << "2. Subtraction\n"
                << "3. Multiplication\n"
                << "4. Division\n"
                << "5. Exponentiation\n"
                << "6. Exit" << '\n' ;

            cout << "Enter your choice: " ;
            cin >> userChoice ;
            cout << '\n' ;

            // Display Error Message
            if (!(userChoice >= 1 && userChoice <= 6))
            {
                cout << "\nInvalid input! Please enter an integer between 1 and 6!\n" << '\n' ;
            }

            // Clear and ignore invalid input
            cin.clear() ;
            cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
        } while (!(userChoice >= 1 && userChoice <= 6)) ; 

        // Select appropriate function
        switch (userChoice)
        {
        case 1: // Add
            num1 = ask_num("Enter the first number: ") ;
            num2 = ask_num("Enter the second number: ") ;
            cout << "Result: "
            << num1 << " + " 
            << num2 << " = " 
            << add(num1, num2) << '\n' ;
            break ;
        case 2: // Subtract
            num1 = ask_num("Enter the first number: ") ;
            num2 = ask_num("Enter the second number: ") ;
            cout << "Result: "
            << num1 << " - " 
            << num2 << " = " 
            << subtract(num1, num2) << '\n' ;
            break ;
        case 3: // Multiply
            num1 = ask_num("Enter the first number: ") ;
            num2 = ask_num("Enter the second number: ") ;
            cout << "Result: "
            << num1 << " * " 
            << num2 << " = " 
            << multiply(num1, num2) << '\n' ;
            break ;
        case 4: // Divide
            num1 = ask_num("Enter the first number: ") ;
            num2 = ask_num("Enter the second number: ") ;
            cout << "Result: "
            << num1 << " / " 
            << num2 << " = " 
            << divide(num1, num2) << '\n' ;
            break ;
        case 5: // Exponentiate
            num1 = ask_num("Enter the first number: ") ;
            num2 = ask_num("Enter the second number: ") ;
            cout << "Result: "
            << num1 << " ^ " 
            << num2 << " = " 
            << exponentiate(num1, num2) << '\n' ;
            break ;
        case 6: // Exit Program
            cout << "Thank you for using the calculator." << '\n' ;
            return 0 ;
            break ;
        default:
            cout << "ERROR: User Select Menu selection undefined. Try again!" << '\n' ;
            break ;
        }

        // Give user a choice to perform another operation
        char aChoice ;
        cout << "Do you want to perform another operation? (y/n): " ;
        cin >> aChoice ;
        if (aChoice == 'y')
        {
            cout << '\n' ;
            continue ;
        }
        else
        {
            cout << "Thank you for using the calculator." << '\n' ;
            tryAgain = false ;
        }
        
    } while (tryAgain == true) ;

    return 0 ;
}

/*
******************************************************
Post-Assigment Reflection

I discovered that some variables should have default values, particularly those
that are assigned a value inside a loop with a guard condition that depends on the value of
the variable to be assigned. Otherwise it will lead to
the loop not deterministically executing as intended (randomly executes or not). Which can
disrupt the execution flow of a program and cause undefined behavior. A do-while loop
can also guarantee that the loop executes at least once and the variable has a proper value
assigned to it.

I used a few nested loops for input validation and a program loop that allows the
user to request successive calculations.


******************************************************
*/