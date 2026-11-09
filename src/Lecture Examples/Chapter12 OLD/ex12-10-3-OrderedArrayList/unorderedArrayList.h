#ifndef H_unorderedArrayList
#define H_unorderedArrayList

#include "arrayList.h"

template <class T>
class unorderedArrayList : public arrayList<T>
{
public:
    unorderedArrayList(int size = 100) ;

    void insertAt(int location, const T& insertItem) override ;
    void insertEnd(const T& insertItem) override ;
    void remove(const T& removeItem) override ;
};

// unorderedArrayList Constructor
template <class T>
unorderedArrayList<T>::unorderedArrayList(int size)
    : arrayList<T>(size)
{
}

// Insert an element at a specific location
template <class T>
void unorderedArrayList<T>::insertAt(int location, const T& insertItem)
{
    if (this->isFull())
    {
        std::cout << "Cannot insert in a full list." << std::endl ;
        return ;
    }

    if (location < 0 || location > this->length)
    {
        std::cout << "The position of the item to be inserted is out of range." << std::endl ;
        return ;
    }

    for (int i = this->length; i > location; i--)
    {
        this->list[i] = this->list[i - 1] ;
    }

    this->list[location] = insertItem ;
    this->length++ ;
}

// Insert an element at the end of the list
template <class T>
void unorderedArrayList<T>::insertEnd(const T& insertItem)
{
    if (this->isFull())
    {
        std::cout << "Cannot insert in a full list." << std::endl ;
        return ;
    }

    this->list[this->length] = insertItem ;
    this->length++ ;
}

// Remove an element from the list
template <class T>
void unorderedArrayList<T>::remove(const T& removeItem)
{
    for (int i = 0; i < this->length; i++)
    {
        if (this->list[i] == removeItem)
        {
            this->removeAt(i) ;
            return ;
        }
    }

    std::cout << "Item not found in the list." << std::endl ;
}

#endif
