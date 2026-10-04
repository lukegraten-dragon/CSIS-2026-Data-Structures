/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 05 Part 1
// Date Modified: 10-04-2026
//
/******************************************************/

# include <iostream>
# include <iomanip>
using namespace std ;

double fahrenheitToCelsius (double inputFahrenheit)
{
    double celsiusOutput = 0 ;

    celsiusOutput = (inputFahrenheit - 32) / (1.8) ;

    return celsiusOutput ;
}


int main ()
{
    int tempQuantity = 0 ;

    cout << "Enter the number of temperatures to convert: " ;
    cin >> tempQuantity ;

    // Format output
    cout << fixed << setprecision(2) ;  

    // Loop for temperature conversions
    for (int i = 0 ; i < tempQuantity ; i++)
    {
        double TempFahrenheit = 0 ;

        cout << "Enter temperature " << i + 1 
        << " in Fahrenheit: " ;
        cin >> TempFahrenheit ;

        // Convert to Celsius via function call
        cout << "*** Fahrenheit: " << TempFahrenheit
            << "°F"
            << " -> Celsius: " 
            << fahrenheitToCelsius(TempFahrenheit)
            << "°C" 
            << '\n';
    }

    return 0 ;
}
/*
Post Lab Reflection:

In this lab exercise I strengthened my understanding of loops,
user-defined functions, and how I can use input (e.g. loop control variables)
to complete multiple tasks combining these concepts.
*/