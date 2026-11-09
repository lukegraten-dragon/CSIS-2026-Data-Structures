// Virtual Functions and Value Parameters

/*
<1>
The preceding examples show that if a formal parameter, say p of a class type, is either a
reference parameter or a pointer and p uses a virtual function of the base class, we can
effectively pass a derived class object as an actual parameter to p.

However, if p is a value parameter, then this mechanism of passing a derived class
object as an actual parameter to p does not work, even if p uses a virtual function.

Recall that if a formal parameter is a value parameter, the value of the actual parameter
is copied into the formal parameter. Therefore, if a formal parameter is of a class
type, the member variables of the actual object are copied into the corresponding
member variables of the formal parameter.
*/

#include <iostream>

using namespace std ;

class petType
{
public:
    virtual void print() const ; // <-- virtual function
    petType(string n = "") ;
private:
    string name ;
} ;

class dogType: public petType
{
public:
    void print() const;
    dogType(string n = "", string b = "") ;
private:
    string breed ;
} ;

/*
<2>
Suppose that we have the above classes—that is, petType and dogType. 
Consider the following function definition:
*/
void callPrint(petType p) //p is a value parameter
{
    p.print() ; // <-- petType's print() or dogType's print()?
}

int main()
{
    petType pet("Lucky") ;                           //Line 3
    dogType dog("Tommy", "German Shepherd") ;        //Line 4

    pet.print() ;                                    //Line 5
    cout << endl ;                                   //Line 6
    
    dog.print() ;                                    //Line 7
    cout << "*** Calling the function callPrint ***"
         << endl ;                                   //Line 8
    
    callPrint(pet) ;                                 //Line 9
    cout << endl ;                                   //Line 10
    
    callPrint(dog) ;                                 //Line 11
    cout << endl ;                                   //Line 12

    /*
    <3>
    Look closely at the output of the statements in Lines 9 and 11 (the last two lines of output).
    In Line 11, because the formal parameter p is a value parameter, the member variables
    of dog are copied into the corresponding member variables of p. However, because
    p is an object of base type petType, it has only the one member variable name. Consequently,
    only the member variable name of dog is copied into the member variable name
    of p. Moreover, the statement p.print(); in the function callPrint executes the function
    print of the base class petType, not of the derived class dogType. Therefore,
    the last line of the output shows only the value of name (the member variable of dog).
    */

    return 0 ;
}

void petType::print() const
{
    cout << "Name: " << name ;
}

petType::petType(string n)
{
    name = n ;
}

void dogType::print() const
{
    petType::print() ;
    cout << ", Breed: " << breed << endl ;
}

dogType:: dogType(string n, string b): petType(n)
{
    breed = b ;
}

/*
    Value parameters and object slicing

    The callPrint parameter differs from the preceding examples:

        12-9-1: void callPrint(petType& p)   // reference parameter
        12-9-2: void callPrint(petType* p)   // pointer parameter
        12-9-3: void callPrint(petType  p)   // value parameter

    Here, petType::print() is virtual, but callPrint(dog) still calls
    petType::print(). The reason is object slicing.

    The original dogType object

        dogType dog("Tommy", "German Shepherd");

                     dog (dogType object)
                +----------------------------+
                | petType base-class portion |
                | name = "Tommy"             |
                +----------------------------+
                | dogType portion            |
                | breed = "German Shepherd"  |
                +----------------------------+

        The dog object contains both its petType base-class subobject
        and its own dogType member, breed.

    Copying the object by value

        callPrint(dog);

        void callPrint(petType p)
        {
            p.print();
        }

             main(): dog                     callPrint(): p
        +--------------------------+      +-------------------------+
        | dogType object           |      | petType object          |
        +--------------------------+      +-------------------------+
        | petType portion          | COPY |                         |
        | name = "Tommy"           |----->| name = "Tommy"          |
        +--------------------------+      +-------------------------+
        | dogType portion          |              |
        | breed = "German Shepherd"|              v
        +--------------------------+      petType::print()
                                                |
                                         "Name: Tommy"

        The new petType object p contains only the copied base-class
        portion. Its type has no breed member. This is object slicing.

        The original dog object is unchanged. The sliced object p is a
        separate petType object that exists for the duration of callPrint.

    Virtual dispatch after slicing

        A virtual call does not recover the derived-class portion after
        slicing. The new object p has type petType, not dogType.

             callPrint(dog)
                    |
                    v
          Copy petType portion
                    |
                    v
          p is a petType object
                    |
                    v
                p.print()
                    |
                    v
          petType::print()
                    |
                    v
              Name: Tommy

        Virtual dispatch is consistent with the actual type of p.
        It is the by-value copy, not the absence of virtual, that causes
        the call to use petType::print().

    Passing by reference or pointer

        By reference (12-9-1):

            void callPrint(petType& p)
            {
                p.print();
            }

        By pointer (12-9-2):

            void callPrint(petType* p)
            {
                p->print();
            }

            main(): dog                 function parameter
        +----------------------+     +-----------------------+
        | dogType object       |<----| petType& p  (alias)   |
        | name = "Tommy"       |     +-----------------------+
        | breed = "German      |                 or
        |          Shepherd"   |<----| petType* p  (address) |
        +----------------------+     +-----------------------+
                      |
                      v
               dogType::print()
                      |
                      v
            Name: Tommy, Breed: German Shepherd

        Both forms refer to the existing dogType object. No petType
        copy is created, so the derived-class portion remains present.
        A virtual call is resolved using the actual dogType object.

    Comparison with the preceding examples

        Example  Parameter       Virtual?    Binding / Result for dog
        -------  --------------  ----------  --------------------------
        12-9-0   petType& p       No          Static  -> petType::print()
        12-9-1   petType& p       Yes         Dynamic -> dogType::print()
        12-9-2   petType* p       Yes         Dynamic -> dogType::print()
        12-9-3   petType  p       Yes         Sliced  -> petType::print()

        In 12-9-3, the copied object has type petType. The virtual call
        therefore uses petType::print(), even though the argument passed
        by the caller was originally a dogType object.

    Program output

        Name: Lucky
        Name: Tommy, Breed: German Shepherd
        *** Calling the function callPrint ***
        Name: Lucky
        Name: Tommy

        The first two calls use pet.print() and dog.print() directly.
        The last two calls take a petType object by value, so the final
        call prints only the base-class name.

    Choosing a parameter type

        void processPet(petType p);           // separate petType copy
        void processPet(const petType& p);    // existing object, no copy
        void processPet(const petType* p);    // pointer; may be nullptr

        A value parameter is suitable when a separate petType copy is
        intentional. Passing a dogType by value to such a parameter
        discards its dogType-specific portion.

        A const reference is generally suitable when the function only
        reads an existing object and should preserve virtual dispatch:

            void callPrint(const petType& p)
            {
                p.print();
            }

        A pointer is useful when the interface accepts an address or
        needs to represent the absence of an object:

            void callPrint(const petType* p)
            {
                if (p != nullptr)
                    p->print();
            }

        A pointer parameter does not require dynamic allocation. An
        existing local object can be passed using its address:

            dogType dog("Tommy", "German Shepherd");
            callPrint(&dog);  // for the pointer-parameter version

*/
