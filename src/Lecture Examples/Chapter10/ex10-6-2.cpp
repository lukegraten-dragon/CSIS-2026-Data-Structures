// Classes and Constructors: A Precaution

// As discussed in the preceding section, constructors provide 
// guaranteed initialization of the object’s member variables. 
// Typically, the default constructor is used to initialize the 
// member variables to some default values, and this constructor 
// has no parameters. A constructor with parameters is used to 
// initialize the member variables to some specific values.

// We have seen that if a class has no constructor(s), then the 
// object created is uninitialized because C++ does not 
// automatically initialize variables when they are declared. 
// In reality, if a class has no constructor(s), then C++ 
// automatically provides the default constructor. However, this 
// default constructor does not initialize the object being declared.

// The important things to remember about classes and constructors 
// are the following:
// - If a class has no constructor(s), C11 automatically provides the default
//   constructor. However, the object declared is still uninitialized.
// - On the other hand, suppose a class, say, dummyClass, includes constructor(s)
//   with parameter(s) and does not include the default constructor. In this case,
//   C++ does not provide the default constructor for the class dummyClass.
//   Therefore, when an object of the class dummyClass is declared, we must
//   include the appropriate arguments in its declaration.

class dummyClass
{
public:
    void print() const ;
    dummyClass(int dX, int dY) ;
private:
    int x ;
    int y ;
} ;

int main()
{
    return 0 ;
}

// The class dummyClass has a constructor with parameters. It does 
// not have a default constructor written for it and C11 will not 
// provide one automatically because at least one constructor has 
// been written for it. Given this definition of the class dummyClass, 
// the following object declaration is legal:
// 
// dummyClass myObject(10, 25); //object declaration is legal
// 
// However, because the class dummyClass does not contain the default 
// constructor, the following declaration is incorrect and would 
// generate a syntax error:
// 
// dummyClass dummyObject; //incorrect object declaration
// 
// Therefore, to avoid such pitfalls, if a class has constructor(s), 
// the class should also include the default constructor.

