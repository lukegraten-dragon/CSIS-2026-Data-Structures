/*
The definiton of the class clockType contains the declarations of the data members
and the function prototypes of the member functions. The definitions of the member
functions are placed in the implementations file. However, in the definition of a class
you can give the complete definition of a member function. Such member functions
definitions are called inline function definitions. Suppose that you want to include
a function to return the hours of a clock. You can write the definition of the class
clockType as follows:
*/
class clockType
{
public:
    void setTime(int hours, int minutes, int seconds) ;
    void getTime(int& hours, int& minutes, int& seconds) const ;
    void printTime() const ;

    void incrementSeconds() ;
    void incrementMinutes() ;
    void incrementHours() ;

    bool equalTime(const clockType& otherClock) const ;

    // Inline Function
    int getHours() const
    {
        return hr ;
    }
    /*
    In this definition of the class, the function getHours is inline. Inline function definitions
    are typically used for very short function definitions. The compiler treats
    inline functions in a special way. It typically inserts the code of an inline function
    at every location the function is called. When a function is called, memory for its
    parameters and local variables is allocated and when the function exits the memory is
    deallocated. So there is an overhead when calling a function. In the case of an inline
    function the overhead of a function invocation is saved. In general, very short definitions
    should be defined as inline functions.
    */

    clockType(int hours = 0, int minutes = 0, int seconds = 0) ;

private:
    int hr ; 
    int min ; 
    int sec ;
} ;
