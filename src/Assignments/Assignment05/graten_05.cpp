/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Assignment 05
// Date Modified: 10-04-2026
//
/******************************************************/
# include <iostream>
# include <string>
# include <fstream>
using namespace std ;

const int MAX_ITEMS = 10 ;

/******************************************************/
// FUNCTIONS
/******************************************************/
void readInventory(string itemName[], int itemQuantity[], int& numItems) 
{
    // Open file
    ifstream inFile ;
    inFile.open("inventory.txt") ; 
    
    // Fill arrays
    if (inFile.is_open())
    { 
        while (inFile && !inFile.eof())
        {
            string currentName = "" ;
            int currentQuantity = 0 ;

            inFile >> currentName >> currentQuantity ;

            itemName[numItems] = currentName ;
            itemQuantity[numItems] = currentQuantity ;

            numItems++ ;
        }
    }
    inFile.close() ; 
}

int calculateTotalItems(int itemQuantity[], int numItems)
{ 
    int totalItems = 0 ; 

    for (int currentItem = 0 ; currentItem < numItems ; currentItem++)
    {
        totalItems = totalItems + itemQuantity[currentItem] ;
    }

    return totalItems ;
}

void findMinMaxStock(string itemName[], int itemQuantities[], int numItems,
    string& minItemName, int& minQuantity, 
    string& maxItemName, int& maxQuantity)
{
    // Temporary variables to pass later on
    string foundMinItemName = "" ;
    string foundMaxItemName = "" ;
    int foundMinQuantity = itemQuantities[0] ;
    int foundMaxQuantity = itemQuantities[0] ;

    // Find item with lowest stock
    for (int currentItem = 0 ; currentItem < numItems ; currentItem++)
    {
        if (itemQuantities[currentItem] < foundMinQuantity)
        {
            foundMinQuantity = itemQuantities[currentItem] ;
            foundMinItemName = itemName[currentItem] ;
        }

        if (itemQuantities[currentItem] > foundMaxQuantity)
        {
            foundMaxQuantity = itemQuantities[currentItem] ;
            foundMaxItemName = itemName[currentItem] ;
        }
    }

    // Set referenced variables to the found item names and their stock
    minItemName = foundMinItemName ;
    minQuantity = foundMinQuantity ;
    maxItemName = foundMaxItemName ;
    maxQuantity = foundMaxQuantity ;
}

void writeReport(string itemName[], int itemQuantities[], 
    int numItems, int totalItems,
    string minItemName, int minQuantity, 
    string maxItemName, int maxQuantity)
{
    // Create output file
    ofstream outFile ;
    outFile.open("report.txt") ;

    int columnWidth = 25 ;
    string dividerLine = "---------------------------------" ;

    // Print Header
    outFile << left << setw(columnWidth) << "Item Name" 
        << setw(columnWidth) << "Quantity" ;
    outFile << "\n" << dividerLine << '\n' ;

    // Print items and their stocks
    for (int currentItem = 0 ; currentItem < numItems ; currentItem++)
    {
        outFile << setw(columnWidth) << itemName[currentItem]
                << setw(columnWidth) << itemQuantities[currentItem]
                << '\n' ;
    }
    outFile << dividerLine << '\n' ;

    // Print Highest and lowest stocked items
    outFile << "Total number of items: "
            << totalItems << '\n' ;
    outFile << "Item with the highest stock: "
            << maxItemName 
            << " (" << maxQuantity << ")" << '\n' ;
    outFile << "Item with the lowest stock: "
            << minItemName 
            << " (" << minQuantity << ")" << '\n' ;

    outFile.close() ;
}

int main()
{
    string items[MAX_ITEMS] ;
    int quantities[MAX_ITEMS] ;
    int numItems = 0 ;

    readInventory(items, quantities, numItems) ;
    
    if (numItems == 0)
    {
        cout << "No data was read from the file." << endl ;
        return 1 ;
    }

    int totalItems = calculateTotalItems(quantities, numItems) ;
    string minItem, maxItem ;
    int minQuantity, maxQuantity ;

    findMinMaxStock(items, quantities, numItems, minItem, minQuantity, maxItem, maxQuantity) ;
    
    writeReport(items, quantities, numItems, totalItems, minItem, minQuantity, maxItem, maxQuantity) ;

    cout << "Report written to report.txt" << endl ;

    return 0 ;
}

/*
Post Assignment Reflection:

In this assignment I strengthened my understanding of using
fstream to read and write data to files. While writing data to
the report.txt output file, I used formatting manipulators (e.g. setw()) to ensure
that the output is clean and readable.

I also used Pass-By-Reference to update external values without
creating a copy or requiring a return statement. The numItems
variable was a great of example of using a while loop
to derive the number of different items in our warehouse.

Something I found challenging was implementing the readInventory
function. I revisited code I created in a previous assignment
to help refresh my memory on how to use fstream to read from files. I
also found out that an array is passed through reference when used
as a function parameter, and I initially thought that I had to pass
it using &. But it wasn't necessary and the compiler warned me about
that.

Something new that I learned was developing functions
based on constraints imposed by main() or preexisting code. 
While it made my job easier that
there was already a main() prewritten. I had to be very intentional
on how I implemented my other functions so that they were compatible with
the code in main().

I found that creating a separate cpp file to test sections of the code I was implementing
to be helpful. As I could ensure that each individual function correctly worked.
*/