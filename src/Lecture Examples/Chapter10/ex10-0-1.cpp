#include <iostream>

using namespace std ;

class courseType
{
public:
    void setCourseInfo(string cName, string cNo, int credits)   ;
    void print() const ;
    int  getCredits() ;
    string getCourseNumber() ;
    string getCourseName() ;
private:
    string courseName ;
    string courseNo ;
    int courseCredits ;

// - If a member of a class is a variable, you declare it just like 
//   any other variable. Also, in C++ versions prior to C++ 11, in the 
//   definition of the class, you cannot initialize a variable when 
//   you declare it.
// - If a member of a class is a function, you typically use the function 
//   prototype to declare that member.
// - If a member of a class is a function, it can (directly) access 
//   any member of the class—member variables and member functions. 
//   That is, when you write the definition of a member function, 
//   you can directly access any member variable of the class without 
//   passing it as a parameter. The only condition is that you must 
//   declare an identifier before you can use it.

// In C++, class is a reserved word, and it defines only a data type; 
// no memory is allocated. It announces the declaration of a class. 
// Moreover, note the semicolon (;) after the right brace. The semicolon 
// is part of the syntax. A missing semicolon, therefore, will result 
// in a syntax error.

// The members of a class are classified into three categories: 
// private, public, and protected. This chapter mainly discusses the 
// first two types, private and public. In C++, private, protected, 
// and public are reserved words and are called member access specifiers.

// Following are some facts about public and private members of a class:
// - By default, all members of a class are private.
// - If a member of a class is private, you cannot access it directly 
//   from outside of the class. (Example 10-1 illustrates this concept.)
// - A public member is accessible outside of the class. 
//   (Example 10-1 illustrates this concept.)
// - To make a member of a class public, you use the member access 
//   specifier public with a colon, :.

} ;


int main()
{


    return 0 ;
}