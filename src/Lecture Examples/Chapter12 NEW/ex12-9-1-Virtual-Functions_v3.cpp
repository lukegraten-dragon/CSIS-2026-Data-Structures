// Virtual Functions

/*
So, during program execution, how does C++ correct this problem of making the call 
to the appropriate function? 
    
C++ corrects this problem by providing the mechanism of "virtual functions". 
The binding of virtual functions occurs at program execution time, not at compile time. 
This kind of binding is called "run-time binding", late binding, or dynamic binding. 
More formally, in run-time binding, the compiler does not generate the code to call 
a specific function. Instead, it generates enough information to enable the run-time 
system to generate the specific code for the appropriate function call. 
Run-time binding is also known as "dynamic binding".

In C++, virtual functions are declared using the reserved word virtual. 
Let us redefine the previous classes using this feature.

Declaring print() virtual in the base class is sufficient; the derived
class does not need to repeat the virtual keyword.
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

void callPrint(petType& p)
{
    p.print() ; // <-- petType's print() or dogType's print()?
}

int main()
{
    petType pet("Lucky") ;                    //Line 3
    dogType dog("Tommy", "German Shepherd") ; //Line 4

    pet.print() ;                             //Line 5
    cout << endl ;                            //Line 6
    
    dog.print() ;                             //Line 7
    cout << "*** Calling the function callPrint ***"
        << endl ;                             //Line 8
    
    callPrint(pet) ;                          //Line 9
    cout << endl ;                            //Line 10
    
    callPrint(dog) ;                          //Line 11
    cout << endl ;                            //Line 12

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
    The class dogType is derived from petType. Both classes have a
    print() member function, but print() is declared virtual in petType.

                  +---------------------------+
                  |          petType          |
                  +---------------------------+
                  | - name                    |
                  | + virtual print() const   |
                  +---------------------------+
                               ^
                               |
                         inheritance
                               |
                  +---------------------------+
                  |          dogType          |
                  +---------------------------+
                  | - breed                   |
                  | + print() const           |
                  +---------------------------+

    The print() function is virtual because of its declaration in
    petType. The matching function in dogType overrides it without
    repeating virtual. Writing "void print() const override;" would
    also let the compiler check the override.

    The function callPrint receives a petType reference:

        void callPrint(petType& p)
        {
            p.print();
        }

    A petType reference can refer to a petType object or to the petType
    portion of a dogType object. Passing dog to callPrint does not make
    a copy of dog or remove its dogType portion.

    When callPrint(pet) executes:

        main()                           callPrint(petType& p)
        +-----------------+              +---------------------+
        | pet: petType    | <----------- | p refers to pet     |
        | name = "Lucky"  |              | p.print()           |
        +-----------------+              +----------+----------+
                                                   |
                                                   v
                                           petType::print()
                                                   |
                                                   v
                                               Name: Lucky

    When callPrint(dog) executes:

        main()                           callPrint(petType& p)
        +-------------------------+      +---------------------+
        | dog: dogType            | <--- | p refers to dog     |
        | petType part:           |      | p.print()           |
        |   name = "Tommy"        |      +----------+----------+
        | dogType part:           |                 |
        |   breed =              |                 | virtual call
        |   "German Shepherd"    |                 v
        +-------------------------+         dogType::print()
                                                   |
                                          +--------+---------+
                                          |                  |
                                          v                  v
                                 petType::print()    print breed
                                          |                  |
                                          +--------+---------+
                                                   |
                                                   v
                                 Name: Tommy, Breed: German Shepherd

    Although p has the declared type petType&, the virtual call p.print()
    selects the final overrider according to the actual object. This is
    dynamic binding (run-time binding) and enables run-time polymorphism.

    The print() implementation in dogType explicitly calls
    petType::print() to print the name before printing the breed:

        void dogType::print() const
        {
            petType::print();
            cout << ", Breed: " << breed << endl;
        }

    The qualified call petType::print() calls the base-class function
    directly; it does not perform virtual dispatch at that call site.

    The four calls in main() invoke:

        pet.print()       -> petType::print()
        dog.print()       -> dogType::print()
        callPrint(pet)    -> petType::print()
        callPrint(dog)    -> dogType::print()

    Program output:

        Name: Lucky
        Name: Tommy, Breed: German Shepherd
        *** Calling the function callPrint ***
        Name: Lucky
        Name: Tommy, Breed: German Shepherd

    Blank lines also occur because of the endl statements in main().

    In ex12-9-0, petType::print() was not declared virtual. Therefore,
    callPrint(dog) selected petType::print() based on the declared type
    petType& and printed only "Name: Tommy" (static binding). In this
    example, virtual dispatch selects dogType::print() instead:

        Without virtual                  With virtual
        ----------------                  ------------
        callPrint(dog)                   callPrint(dog)
               |                                |
               v                                v
        petType& p                       petType& p
               |                                |
               v                                v
        petType::print()                 dogType::print()
               |                                |
               v                                v
        Name: Tommy                     Name: Tommy, Breed: German Shepherd

    Both programs use p.print() inside callPrint(). The virtual
    declaration changes which implementation is called for dog.
*/
