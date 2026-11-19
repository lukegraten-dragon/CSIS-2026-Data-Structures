#include "arrayList.h"
#include <iostream>
#include <cassert>

using namespace std;

bool arrayList::isEmpty() const
{
    return length == 0 ;
}

bool arrayList::isFull() const
{
    return length == maxSize ;
}

int arrayList::listSize() const
{
    return length ;
}

int arrayList::maxListSize() const
{
    return maxSize ;
}

void arrayList::print() const
{
    if (isEmpty())
    {
        cout << "List is empty." << endl ;
        return ;
    }

    for (int i = 0; i < length; ++i)
    {
        cout << list[i] << " " ;
    }
    cout << endl ;
}

void arrayList::removeAt(int location)
{
    if (location < 0 || location >= length)
    {
        cout << "Location out of range." << endl ;
        return ;
    }

    // Shift elements to the left to remove the item
    for (int i = location; i < length - 1; ++i)
    {
        list[i] = list[i + 1] ;
    }

    length-- ;  // Decrement the length of the list
}

int arrayList::elementAt(int location) const
{
    assert(location >= 0 && location < length) ; // Ensure location is within bounds
    return list[location] ;
}

void arrayList::clearList()
{
    length = 0 ;  // Reset the list to empty
}

arrayList::arrayList(int size)
{
    if (size <= 0)
    {
        cout << "Array size must be positive. Creating a list of size 100." << endl ;
        maxSize = 100 ;
    }
    else
    {
        maxSize = size ;
    }

    list = new int[maxSize] ; // Dynamically allocate memory for the list
    length = 0 ;
}

arrayList::arrayList(const arrayList& otherList)
{
    maxSize = otherList.maxSize ;
    length = otherList.length ;
    list = new int[maxSize] ;  // Allocate memory for the new list

    for (int i = 0; i < length; ++i)
    {
        list[i] = otherList.list[i] ;  // Copy elements from otherList
    }
}

arrayList::~arrayList()
{
    delete[] list ;  // Deallocate the memory used by the list
}
