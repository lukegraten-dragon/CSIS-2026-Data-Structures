// Static Members

/*
In Chapter 6, we described two types of variables: automatic and static. Recall that
if a local variable of a function is static, it exists between function calls. Similar to
static variables, a class can have static members, functions, or variables. Let us
note the following about the static members of a class:
- If a function of a class is static, in the class definition it is declared
  using the keyword static in its heading.
- If a member variable of a class is static, it is declared using the keyword
  static, as discussed in Chapter 6 and also illustrated in Example 10-12.
- A public static member, function, or variable of a class can be
  accessed using the class name and the scope resolution operator.
*/
class illustrate
{ 
public: 
    static int count ;	//public static variable

    void print() const ;
      //Function to output x, y, and count.

    void setX(int a) ;
      //Function to set x.
      //Postcondition: x = a ;

    static void incrementY() ;
      //static function
      //Function to increment y by 1.
      //Postcondition: y = y + 1

    illustrate(int a = 0) ;
      //constructor 
      //Postcondition: x = a ;
      //               If no value is specified for a, x = 0 ;

private:
    int x ;
    static int y ;	//private static variable
} ;
