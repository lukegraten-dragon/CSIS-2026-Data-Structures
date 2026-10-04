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
        // 
        while (inFile && !inFile.eof())
        {
            string currentName = "" ;
            int currentQuantity = 0 ;

            inFile >> currentName >> currentQuantity ;

            itemName[numItems] = currentName ;
            itemQuantity[numItems] = currentQuantity ;

            numItems++ ;
        }

        // // TEST: Loop to check values in arrays
        // cout << "Number of items in arrays: " << numItems << '\n' ;
        // for (int i = 0 ; i < numItems ; i++)
        // {
        //     cout << "itemName " << i << ": " << itemName[i] << '\n' ;
        //     cout << "itemQuantity " << i << ": " << itemQuantity[i] << '\n' ;
        // }
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

    // //TEST: Check total quantity of items in warehouse
    // cout << "Total Items in Warehouse: " << totalItems << '\n' ;

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

    // // TEST: Print Item with the lowest stock
    // cout << "Item with Lowest Stock: "
    //     << foundMinItemName
    //     << "\nStock: "
    //     << foundMinQuantity << '\n' ;

    // // TEST: Print Item with the higest stock
    // cout << "Item with Highest Stock: "
    //     << foundMaxItemName
    //     << "\nStock: "
    //     << foundMaxQuantity << '\n' ;

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