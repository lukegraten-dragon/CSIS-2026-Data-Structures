#include <iostream>

using namespace std ;

// Suppose that we want to define a class to implement the time 
// of day in a program. Because a clock gives the time of day, 
// let us call this class clockType. Furthermore, to represent 
// time in computer memory, we use three int variables: one to represent
// the hours, one to represent the minutes, and one to represent the seconds.

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
    // The word 'const' at the end of the member functions getTime,
    // printTime, and equalTime specifies that these functions cannot
    // modify the member variables of a variable of type clockType.
private:
    int hr ;
    int min ;
    int sec ;

// Some members of the class clockType will be private; 
// others will be public. Deciding which member to make public and 
// which to make private depends on the nature of the member. 
// The general rule is that any member that needs to be directly 
// accessed outside of the class is declared public; any member that 
// should not be accessed directly by the user should be declared private. 
// For example, the user should be able to set the time and print the time. 
// Therefore, the members that set the time and print the time should be 
// declared public.

// Similarly, the members to increment the time and compare the time for 
// equality should be declared public. On the other hand, to prevent the 
// direct manipulation of the member variables hr, min, and sec, we will 
// declare them private. Furthermore, note that if the user has direct 
// access to the member variables, member functions such as setTime are 
// not needed. The second part of this chapter (beginning with the section 
// “Information Hiding”) explains why some members need to be public and 
// others should be private.

} ;

int main()
{


    return 0 ;
}