// Arrays in structs

#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std ;

const int ARRAY_SIZE = 10 ;

struct listType
{
    int listElem[ARRAY_SIZE] ; //array containing the list
    int listLength ;           //length of the list
} ;

int seqSearch(const listType& list, int searchItem) ;

int main()
{
    listType intList ;

    // intList.listLength = 0 ;
    // intList.listElem[0] = 12 ;
    // intList.listLength++ ;
    // intList.listElem[1] = 37 ;
    // intList.listLength++ ;

    // Initialize random seed
    srand(time(0)) ;

    // Fill the array with random numbers between 1 and 100
    for (int i=0; i<ARRAY_SIZE; i++) {
        intList.listElem[i] = rand() % 100 + 1 ;
    }

    // Print intList.listElem
    cout << "Array elements: " ;
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        cout << intList.listElem[i] << " " ;
    }
    cout << endl ;

    int location = seqSearch(intList, 19) ;

    if (location == -1)
        cout << "The search item is NOT in the intList." << endl ;
    else
        cout << "Found. Its location: " << location << endl ;

    return 0 ;
}

int seqSearch(const listType& list, int searchItem)
{
    int loc ;
    bool found = false ;

    for (loc = 0; loc < list.listLength; loc++)
        if (list.listElem[loc] == searchItem)
        {
            found = true ;
            break ;
        }
    if (found)
        return loc ;
    else
        return -1 ;
}
