// Data Abstraction, Classes, and Abstract Data Types

/*
For the car that we drive, most of us want to know how to start the car and drive it.
Most people are not concerned with the complexity of how the engine works. By
separating the design details of a car’s engine from its use, the manufacturer helps
the driver focus on how to drive the car. Our daily life has other similar examples. For
the most part, we are concerned only with how to use certain items, rather than with
how they work.
Separating the design details (that is, how the car’s engine works) from its use is
called abstraction. In other words, abstraction focuses on what the engine does
and not on how it works. Thus, 'abstraction' is the process of separating the logical
properties from the implementation details. Driving the car is a logical property;
the construction of the engine constitutes the implementation details. We have an
abstract view of what the engine does but are not interested in the engine’s actual
implementation.

Abstraction can also be applied to data. Earlier sections of this chapter defined a data
type clockType. The data type clockType has three member variables and the following
basic operations:
1. Set the time.
2. Return the time.
3. Print the time.
4. Increment the time by one second.
5. Increment the time by one minute.
6. Increment the time by one hour.
7. Compare two times to see whether they are equal.
The actual implementation of the operations, that is, the definitions of the member
functions of the class clockType, was postponed.

Data abstraction is defined as a process of separating the logical properties of the
data from its implementation. The definition of clockType and its basic operations
are the logical properties; the storing of clockType objects in the computer and the
algorithms to perform these operations are the implementation details of clockType.

Abstract data type (ADT): A data type that separates the logical properties from the
implementation details.
Like any other data type such as int, an ADT has three things associated with it: the
name of the ADT, called the type name; the set of values belonging to the ADT, called
the domain; and the set of operations on the data. (For example, for the data type
int, the type name is int, the domain is the set of integers between –2147483648 and
2147483647 (inclusive), and the operations on int type are +, –, *, /, and %.) Following
these conventions, we can define the clockType ADT as follows:

dataTypeName
    clockType
domain
    Each clockType value is a time of day in the form of hours, minutes, and seconds.
operations
    Set the time.
    Return the time.
    Print the time.
    Increment the time by one second.
    Increment the time by one minute.
    Increment the time by one hour.
    Compare the two times to see whether they are equal.

Example 10-7

A list is defined as a set of values of the same type. Because all values in a list are of
the same type, a convenient way to represent and process a list is to use an array. You
can define a list as an ADT as follows:

dataTypeName
    listType
domain
    Every listType value is an array of, say 1000 numbers
operations
    Check to see whether the list is empty.
    Check to see whether the list is full.
    Search the list for a given item.
    Delete an item from the list.
    Insert an item in the list.
    Sort the list.
    Destroy the list.
    Print the list.

*/

class listType
{
public:
    bool isEmptyList() const ;
    bool isFullList() const ;
    int  search(int searchItem) const ;
    void insert(int newElement) ;
    void remove(int removeElement) ;
    void destroyList() ;
    void printList() const ;
    listType() ; //constructor
private:
    int list[1000] ;
    int length ;
};

int main()
{
    return 0 ;
}
