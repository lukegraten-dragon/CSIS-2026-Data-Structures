#ifndef H_arrayList
#define H_arrayList

#include <iostream>
#include <cassert>

template <class T>
class arrayList
{
public:
    // Constructor
    arrayList(int size = 100) ;
    
    // Copy constructor
    arrayList(const arrayList<T>& otherList) ;
    
    // Destructor
    virtual ~arrayList() ;

    bool isEmpty() const ;
    bool isFull() const ;
    int listSize() const ;
    int maxListSize() const ;

    void print() const ;

    virtual void insertAt(int location, const T& insertItem) = 0 ;
    virtual void insertEnd(const T& insertItem) = 0 ;
    virtual void remove(const T& removeItem) = 0 ;

    void removeAt(int location) ;
    T elementAt(int location) const ;
    void clearList() ;

protected:
    T *list ;    // Pointer to hold the list elements
    int length ; // Current length of the list
    int maxSize ;// Maximum size of the list
};

// Constructor
template <class T>
arrayList<T>::arrayList(int size)
{
    if (size <= 0)
    {
        std::cout << "Array size must be positive. Creating a list of size 100." << std::endl ;
        maxSize = 100 ;
    }
    else
    {
        maxSize = size ;
    }

    list = new T[maxSize] ; // Dynamically allocate memory for the list
    length = 0 ;
}

// Copy Constructor
template <class T>
arrayList<T>::arrayList(const arrayList<T>& otherList)
{
    maxSize = otherList.maxSize ;
    length = otherList.length ;
    list = new T[maxSize] ; // Allocate memory for the new list

    for (int i = 0; i < length; ++i)
    {
        list[i] = otherList.list[i] ; // Copy elements from otherList
    }
}

// Destructor
template <class T>
arrayList<T>::~arrayList()
{
    delete[] list ; // Deallocate the memory used by the list
}

// Check if the list is empty
template <class T>
bool arrayList<T>::isEmpty() const
{
    return length == 0 ;
}

// Check if the list is full
template <class T>
bool arrayList<T>::isFull() const
{
    return length == maxSize ;
}

// Get the current size of the list
template <class T>
int arrayList<T>::listSize() const
{
    return length ;
}

// Get the maximum size of the list
template <class T>
int arrayList<T>::maxListSize() const
{
    return maxSize ;
}

// Print the list elements
template <class T>
void arrayList<T>::print() const
{
    if (isEmpty())
    {
        std::cout << "List is empty." << std::endl ;
        return ;
    }

    for (int i = 0; i < length; ++i)
    {
        std::cout << list[i] << " " ;
    }
    std::cout << std::endl ;
}

// Remove an element at a specific location
template <class T>
void arrayList<T>::removeAt(int location)
{
    if (location < 0 || location >= length)
    {
        std::cout << "Location out of range." << std::endl ;
        return ;
    }

    // Shift elements to the left to remove the item
    for (int i = location; i < length - 1; ++i)
    {
        list[i] = list[i + 1] ;
    }

    length-- ; // Decrement the length of the list
}

// Get the element at a specific location
template <class T>
T arrayList<T>::elementAt(int location) const
{
    assert(location >= 0 && location < length) ; // Ensure location is within bounds
    return list[location] ;
}

// Clear the list by resetting the length
template <class T>
void arrayList<T>::clearList()
{
    length = 0 ; // Reset the list to empty
}

#endif
