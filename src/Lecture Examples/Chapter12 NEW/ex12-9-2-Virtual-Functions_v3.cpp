// Virtual Functions

/*
The previous discussion also applies when a formal parameter is a pointer to a class,
and a pointer of the derived class is passed as an actual parameter. To illustrate this
feature, suppose we have the preceding classes.
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

void callPrint(petType *p)
{
    p->print() ; // <-- petType's print() or dogType's print()?
}

int main()
{
    petType *q ;                                     //Line 3
    dogType *r ;                                     //Line 4

    q = new petType("Lucky") ;                       //Line 5
    r = new dogType("Tommy", "German Shepherd") ;    //Line 6
    
    q->print() ;                                     //Line 7
    cout << endl ;                                   //Line 8
    
    r->print() ;                                     //Line 9
    cout << "*** Calling the function callPrint ***"
         << endl ;                                   //Line 10
    
    callPrint(q) ;                                   //Line 11
    cout << endl ;                                   //Line 12
    
    callPrint(r) ;                                   //Line 13

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
    The class petType declares print() as a virtual function. The class
    dogType inherits from petType and provides its own print() function.

                 +--------------------------+
                 |         petType          |
                 +--------------------------+
                 | name                     |
                 | virtual print() const    |
                 +--------------------------+
                              ^
                              | inheritance
                              |
                 +--------------------------+
                 |         dogType          |
                 +--------------------------+
                 | breed                    |
                 | print() const            |
                 +--------------------------+

    Declaring print() virtual in petType also makes the matching
    dogType::print() virtual. The derived class may use the declaration
    "void print() const override;" so the compiler checks the override.

    In main(), q and r hold addresses of two dynamically allocated objects:

          main()                         Dynamically allocated objects
       +---------------+               +---------------------------+
       | q (petType*)  | ------------> | petType                   |
       +---------------+               | name = "Lucky"            |
                                       +---------------------------+

       +---------------+               +---------------------------+
       | r (dogType*)  | ------------> | dogType                   |
       +---------------+               | petType part:             |
                                       |   name = "Tommy"          |
                                       | dogType part:             |
                                       |   breed =                 |
                                       |   "German Shepherd"       |
                                       +---------------------------+

    The function callPrint receives a base-class pointer:

        void callPrint(petType *p)
        {
            p->print();
        }

    A petType* can point to either a petType object or the petType base
    subobject of a dogType object. The argument is passed by value, so p
    receives a copy of the address; no petType or dogType object is copied.

    For callPrint(q):

        q (petType*) ----> petType object ("Lucky")
                                   ^
                                   |
        p (petType*) ---------------+
                                   |
                                   v
                            petType::print()
                                   |
                                   v
                               Name: Lucky

    For callPrint(r):

        r (dogType*) ----> dogType object ("Tommy", "German Shepherd")
                                   ^
                                   |
        p (petType*) ---------------+
                                   |
                                   v
                            p->print()  [virtual]
                                   |
                                   v
                            dogType::print()
                                   |
                                   +--> petType::print() prints the name
                                   +--> dogType::print() prints the breed
                                   |
                                   v
                      Name: Tommy, Breed: German Shepherd

    The declared type of p is petType*, but the object it points to in
    callPrint(r) is a dogType. Virtual dispatch selects dogType::print()
    according to the actual object type. The explicitly qualified call
    petType::print() inside dogType::print() directly calls the base
    implementation rather than performing another virtual dispatch.

    The calls in main() invoke:

        q->print()       -> petType::print()
        r->print()       -> dogType::print()
        callPrint(q)     -> petType::print()
        callPrint(r)     -> dogType::print()

    Program output:

        Name: Lucky
        Name: Tommy, Breed: German Shepherd
        *** Calling the function callPrint ***
        Name: Lucky
        Name: Tommy, Breed: German Shepherd

    Comparison with the preceding examples:

        Example    Parameter       Virtual function      Binding
        ------------------------------------------------------------
        12-9-0     petType& p      No                    Static
        12-9-1     petType& p      Yes                   Dynamic
        12-9-2     petType* p      Yes                   Dynamic

    The difference can be seen by calling the function with a dogType
    object (or a pointer to it):

        12-9-0: callPrint(dog) -> petType::print() -> Name: Tommy
        12-9-1: callPrint(dog) -> dogType::print() -> Name and breed
        12-9-2: callPrint(r)   -> dogType::print() -> Name and breed

    In 12-9-0, print() is nonvirtual, so the call through petType& selects
    petType::print() based on the declared parameter type (static binding).
    In 12-9-1 and 12-9-2, virtual dispatch selects the final overrider for
    the actual object (dynamic binding). Both references and pointers can
    support virtual dispatch; allocating an object with new is not required.

    The parameter type depends on the required behavior and whether
    the caller can supply an object:

        Nonvirtual member function:
            Appropriate for behavior that should remain the base-class
            implementation when accessed through a base reference or
            pointer. It should not be used when derived-class-specific
            behavior is expected through that interface.

        Virtual function with a reference (petType&):
            Appropriate when the caller must provide an existing object.
            The reference refers to that object and is not nullable in
            ordinary use. This is often the simpler function interface.

        Virtual function with a pointer (petType*):
            Appropriate when a pointer is already available, or when the
            interface allows "no object" through nullptr. If nullptr is
            possible, the function should check before using p->print().

    Pointer-based virtual dispatch works with local objects as well:

        dogType dog("Tommy", "German Shepherd");
        callPrint(&dog);              // Calls dogType::print().

    The objects in this program are allocated with new but are not
    explicitly released. Since q points to a petType object and r points
    to a dogType object, the matching cleanup here would be:

        delete q;
        delete r;

    If a derived object is deleted through a base-class pointer, the
    base class needs a virtual destructor, such as
    "virtual ~petType() = default;". Smart pointers are commonly used
    to manage ownership of dynamically allocated objects.
*/
