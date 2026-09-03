// In-Class Initialization of Data Members and the Default Constructor

#include <iostream>  

using namespace std ; 

// <1>
// C++11 standard allows the initialization of data members when they 
// are declared in a class. For example, the definition of the class 
// clockType can also be written as follows:

class clockType
{
public:
    void setTime(int, int, int) ;
    void getTime(int&, int&, int&) const ;
    void printTime() const ;
    void incrementSeconds() ;
    void incrementMinutes() ;
    void incrementHours() ;
    bool equalTime(const clockType&) const ;

    // <3>
    // Note that even though we have initialized the data members of 
    // the class clockType, we have still included the default constructor. 
    // This is required if you want to declare clockType objects, 
    // such as myTime, without passing any values to them. Also let us 
    // look at the statement that includes the default constructor in 
    // the class definition:
    clockType() ;              // default constructor
    clockType(int, int, int) ; // constructor with parameters

private:
    int hr  = 0 ;
    int min = 0 ;
    int sec = 0 ;
} ;

int main()
{
    // <2>
    // In this class definition, the data members hr, min, and sec 
    // are declared as well as initialized. This is called in-class 
    // initialization of the data members. When an object of the 
    // class clockType is declared without parameters, then the object 
    // is initialized using the in-class initialized values. 
    // If an object is declared with parameters, then the default 
    // values are overridden by the constructor with the parameters. 
    // For example, consider the following statements:
    clockType myTime ;
    // This is a complete definition of the default constructor. 
    // The {} sepcifies the empty body of the default constructor’s 
    // definition. This is an example of in-line function definition 
    // of a class member. Because the complete definition is included 
    // in the class definition, we do not need to provide its definition 
    // in the implementation file. We will discuss in-line member functions 
    // of a class later in this chapter.
    clockType yourTime(3, 40, 18) ;
    // is equivalent to the statement:
    // clockType myClock = clockType(3, 40, 18) ;

    return 0 ;
}

clockType::clockType() //default constructor
{
    hr = 0 ;
    min = 0 ;
    sec = 0 ;
}

clockType::clockType(int hours, int minutes, int seconds)
{
    if (0 <= hours && hours < 24)
        hr = hours ;
    else
        hr = 0 ;

    if (0 <= minutes && minutes < 60)
        min = minutes ;
    else
        min = 0 ;

    if (0 <= seconds && seconds < 60)
        sec = seconds ;
    else
        sec = 0 ;
}
