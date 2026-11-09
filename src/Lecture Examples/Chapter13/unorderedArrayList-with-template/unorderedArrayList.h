#ifndef H_unorderedArrayList
#define H_unorderedArrayList

#include "arrayList.h"

class unorderedArrayList : public arrayList
{
public:
    unorderedArrayList(int size = 100) ;
    // Constructor to create a list with the specified maximum size (default is 100).

    void insertAt(int location, int insertItem) override ;
    // Inserts the item at the specified location.

    void insertEnd(int insertItem) override ;
    // Inserts the item at the end of the list.

    void remove(int removeItem) override ;
    // Removes the specified item from the list, if found.

};

#endif
