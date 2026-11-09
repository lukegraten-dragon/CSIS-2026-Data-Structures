#include "orderedArrayList.h"
#include <iostream>

using namespace std;

orderedArrayList::orderedArrayList(int size) : arrayList(size)
{
    // Calls the base class constructor with the given size
}

void orderedArrayList::insertAt(int location, int insertItem)
{
    // Since the list is ordered, we don't allow arbitrary insertions at a given location
    cout << "Insertion at a specific location is not allowed in an ordered list." << endl ;
}

void orderedArrayList::insertEnd(int insertItem)
{
    // Inserting at the end would violate the ordered nature of the list
    cout << "Insertion at the end is not allowed in an ordered list." << endl ;
}

void orderedArrayList::insert(int insertItem)
{
    if (isFull())
    {
        cout << "Cannot insert in a full list." << endl ;
        return ;
    }

    int position = findInsertPosition(insertItem) ;

    // Shift elements to the right to make space for the new item
    for (int i = length; i > position; i--)
    {
        list[i] = list[i - 1] ;
    }

    list[position] = insertItem ;
    length++ ;  // Increment the length of the list
}

void orderedArrayList::remove(int removeItem)
{
    // Find the item to remove
    bool found = false ;
    for (int i = 0; i < length; i++)
    {
        if (list[i] == removeItem)
        {
            removeAt(i) ;  // Use removeAt from the base class to remove the item
            found = true ;
            break ;
        }
    }

    if (!found)
    {
        cout << "Item not found in the list." << endl ;
    }
}

int orderedArrayList::findInsertPosition(int insertItem) const
{
    // Perform a linear search to find the correct position for the new item
    int position = 0 ;
    while (position < length && list[position] < insertItem)
    {
        position++ ;
    }
    return position ;
}
