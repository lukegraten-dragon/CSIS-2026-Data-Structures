#include <iostream>  
#include <string>

using namespace std ; 

class inventory
{
public:
    inventory() ;        //default constructor
    inventory(string) ;
    inventory(string, int, double) ;
    inventory(string, int, double, int) ;

    //Add additional functions
    void printInventory() ;
private:
    string name ;
    int itemNum ;
    double price ;
    int unitsInStock ;
} ;
// This class has four constructors and four member variables. Suppose 
// that the definitions of the constructors are as follows:

int main()
{
    inventory item1 ;
    inventory item2("Dryer") ;
    inventory item3("Washer", 2345, 278.95) ;
    inventory item4("Toaster", 8231, 34.49, 200) ;

    item1.printInventory() ;
    item2.printInventory() ;
    item3.printInventory() ;
    item4.printInventory() ;
    
    return 0 ;
}

inventory::inventory() // default constructor
{
    name = "" ;
    itemNum = -1 ;
    price = 0.0 ;
    unitsInStock = 0 ;
}

inventory::inventory(string n)
{
    name = n ;
    itemNum = -1 ;
    price = 0.0 ;
    unitsInStock = 0 ;
}

inventory::inventory(string n, int iNum, double cost)
{
    name = n ;
    itemNum = iNum ;
    price = cost ;
    unitsInStock = 0 ;
}

inventory::inventory(string n, int iNum, double cost, int inStock)
{
    name = n ;
    itemNum = iNum ;
    price = cost ;
    unitsInStock = inStock ;
}

void inventory::printInventory()
{
    cout << "*** Inventory" << endl 
         << "Name: " << name << endl 
         << "Item Num: " << itemNum << endl 
         << "Price: " << price << endl 
         << "Units In Stock: " << unitsInStock << endl << endl ;
}