#include "unorderedArrayList.h"
#include <iostream>

using namespace std;

unorderedArrayList::unorderedArrayList(int size) : arrayList(size)
{
    // Calls the base class constructor with the given size
}

void unorderedArrayList::insertAt(int location, int insertItem)
{
    if (isFull())
    {
        cout << "Cannot insert in a full list." << endl ;
        return ;
    }

    if (location < 0 || location > length)
    {
        cout << "The position of the item to be inserted is out of range." << endl ;
        return ;
    }

    // Shift elements to the right to make space for the new item
    for (int i = length; i > location; i--)
    {
        list[i] = list[i - 1] ;
    }

    list[location] = insertItem ;
    length++ ;  // Increment the length of the list
}

void unorderedArrayList::insertEnd(int insertItem)
{
    if (isFull())
    {
        cout << "Cannot insert in a full list." << endl ;
        return ;
    }

    list[length] = insertItem ;  // Insert at the end
    length++ ;  // Increment the length
}

void unorderedArrayList::remove(int removeItem)
{
    // Find the item to remove
    bool found = false;
    for (int i = 0; i < length; i++)
    {
        if (list[i] == removeItem)
        {
            removeAt(i) ;  // Use removeAt from the base class to remove the item
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Item not found in the list." << endl ;
    }
}
