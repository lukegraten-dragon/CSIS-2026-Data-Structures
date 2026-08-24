#include <iostream>

using namespace std ;

int main () 
{
    double salePrice ;        // the selling price of the item
    double stateSalesTax ;    // the state’s sales tax
    double citySalesTax ;     // the city’s sales tax
    double luxuryTax ;        // the luxury tax
    double salesTax ;         // the total sales tax
    double amountDue ;        // the final price of the item

    //salePrice = 60000.00 ;
    cout << "Enter salePrice: " ;
    cin >> salePrice ;

    stateSalesTax = salePrice * 0.04 ;
    citySalesTax = salePrice * 0.015 ;

    if (salePrice >= 50000)
        luxuryTax = salePrice * 0.1 ;
    else
        luxuryTax = 0 ;

    cout << "stateSalesTax = " << stateSalesTax << endl ;
    cout << "citySalesTax = " << citySalesTax << endl ;
    cout << "luxuryTax = " << luxuryTax << endl ;

    salesTax = stateSalesTax + citySalesTax + luxuryTax ;
    amountDue = salePrice + salesTax ;

    cout << "Total Amount = " << amountDue << endl ;

    return 0 ;
}