#ifndef H_arrayList
#define H_arrayList

class arrayList
{
public:
    bool isEmpty() const ;
    // Returns true if the list is empty; otherwise, false.

    bool isFull() const ;
    // Returns true if the list is full; otherwise, false.

    int listSize() const ;
    // Returns the number of elements in the list.

    int maxListSize() const ;
    // Returns the maximum size of the list.

    void print() const ;
    // Outputs the elements of the list to the standard output.

    virtual void insertAt(int location, int insertItem) = 0 ;
    // Inserts the item at the specified location.
    // This is a pure virtual function, meaning derived classes must implement it.

    virtual void insertEnd(int insertItem) = 0 ;
    // Inserts the item at the end of the list.
    // This is a pure virtual function, meaning derived classes must implement it.

    virtual void remove(int removeItem) = 0 ;
    // Removes the specified item from the list, if found.
    // This is a pure virtual function, meaning derived classes must implement it.

    void removeAt(int location) ;
    // Removes the item at the specified location.

    int elementAt(int location) const ;
    // Returns the element at the specified location.
    // If location is out of range, appropriate error handling should be performed.

    void clearList() ;
    // Clears the list by resetting its size to zero.

    arrayList(int size = 100) ;
    // Constructor to create a list with the specified maximum size (default is 100).

    arrayList(const arrayList& otherList) ;
    // Copy constructor to copy another arrayList object.

    virtual ~arrayList() ;
    // Destructor to deallocate memory used by the list.

protected:
    int *list ;    // Pointer to hold the list elements.
    int length ;   // Current length of the list.
    int maxSize ;  // Maximum size of the list.
};

#endif
