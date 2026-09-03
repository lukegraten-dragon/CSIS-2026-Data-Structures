// Reference Parameters and Class Objects (Variables)

#include <iostream>  

using namespace std ; 

class clockType
{
public:
    void setTime(int, int, int) ;
    void testTime(const clockType& otherClock) ;

private:
    int hr ;
    int min ;
    int sec ;
} ;

int main()
{
    clockType myClock ;
    myClock.setTime(2, 26, 47) ;

    // <2>
    // The function testTime contains a reference parameter, otherClock. 
    // The parameter otherClock is declared using the keyword const. 
    // Thus, in a call to the function testTime, the formal parameter 
    // otherClock receives the address of the actual parameter, but 
    // otherClock cannot modify the contents of the actual parameter. 
    // For example, after the following statement executes, the value of 
    // myClock will not be altered:
    //myClock.testTime(myClock) ;
    // In fact, if the function testTime attempts to modify otherClock, 
    // the compiler will generate syntax errors.

    return 0 ;
}

void clockType::setTime(int hours, int minutes, int seconds)
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

// <1>
// If a variable is passed by reference, the formal parameter receives 
// only the address of the actual parameter. Therefore, an efficient way 
// to pass a variable as a parameter is by reference. 
// If a variable is passed by reference, then when the formal parameter 
// changes, the actual parameter also changes. 
// Sometimes, however, you do not want the function to be able to change 
// the values of the member variables. In C++, you can pass a variable 
// by reference and still prevent the function from changing its value 
// by using the keyword 'const' in the formal parameter declaration. 
// As an example, consider the following function definition:
void testTime(const clockType& otherClock)
{
    clockType dClock;

    // <3>
    // Generally, if you want to declare a class object as a value parameter, 
    // you declare it as a reference parameter using the keyword const, as 
    // described previously. Recall that if a formal parameter is a value 
    // parameter, within the function definition, you can change the value of 
    // the formal parameter. That is, you can use an assignment statement to 
    // change the value of the formal parameter (which, of course, would have 
    // no effect on the actual parameter). However, if a formal parameter is 
    // a constant reference parameter, you cannot use an assignment statement 
    // to change its value within the function, nor can you use any other 
    // function to change its value. Therefore, within the definition of the 
    // function testTime, you cannot alter the value of otherClock. 
    // For example, the following would be illegal in the definition of the 
    // function testTime:
    //otherClock.setTime(5, 34, 56) ; //illegal
    //otherClock = dClock ;           //illegal
}
