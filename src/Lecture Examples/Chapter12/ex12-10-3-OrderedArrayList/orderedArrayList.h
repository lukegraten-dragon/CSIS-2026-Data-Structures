#ifndef H_orderedArrayList
#define H_orderedArrayList

#include "arrayList.h"

class orderedArrayList : public arrayList
{
public:
    orderedArrayList(int size = 100) ;
    // Constructor to create a list with the specified maximum size (default is 100).

    void insertAt(int location, int insertItem) override ;
    // Overridden insertAt is not supported in ordered list.

    void insertEnd(int insertItem) override ;
    // Overridden insertEnd is not supported in ordered list.

    void insert(int insertItem) ;
    // Inserts the item in its correct position (keeping the list ordered).

    void remove(int removeItem) override ;
    // Removes the specified item from the list, if found.

private:
    int findInsertPosition(int insertItem) const ;
    // Finds the position where the new item should be inserted.
};

#endif
