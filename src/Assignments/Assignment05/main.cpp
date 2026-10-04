// const int MAX_ITEMS = 10 ;

// int main()
// {
//     string items[MAX_ITEMS] ;
//     int quantities[MAX_ITEMS] ;
//     int numItems = 0 ;

//     readInventory(items, quantities, numItems) ;
    
//     if (numItems == 0)
//     {
//         cout << "No data was read from the file." << endl ;
//         return 1 ;
//     }

//     int totalItems = calculateTotalItems(quantities, numItems) ;
//     string minItem, maxItem ;
//     int minQuantity, maxQuantity ;

//     findMinMaxStock(items, quantities, numItems, minItem, minQuantity, maxItem, maxQuantity) ;
    
//     writeReport(items, quantities, numItems, totalItems, minItem, minQuantity, maxItem, maxQuantity) ;

//     cout << "Report written to report.txt" << endl ;

//     return 0 ;
// }