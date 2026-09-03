// Assignment Operator and Classes

#include <iostream>  

using namespace std ; 

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

private:
    int hr ;
    int min ;
    int sec ;
} ;

int main()
{
    clockType myClock ;
    clockType yourClock ;

    int x = 2 ;
    int y = 19 ;
    int z = 30 ;

    myClock.setTime(2, 26, 47) ;
    yourClock.setTime(14, 39, 28) ;

    cout << "*** Before myClock = yourClock ;" << endl ;

    cout << "    myClock: " ;
    myClock.printTime() ;
    cout << endl ;
    
    cout << "  yourClock: " ;
    yourClock.printTime() ;
    cout << endl ;

    cout << "  &myClock: " << &myClock << endl ;
    cout << "&yourClock: " << &yourClock << endl ;

    myClock = yourClock ;
    // copies the value of yourClock into myClock. That is,
    // - the value of yourClock.hr is copied into myClock.hr,
    // - the value of yourClock.min is copied into myClock.min, and
    // - the value of yourClock.sec is copied into myClock.sec.

    // In other words, the values of the three member variables of 
    // yourClock are copied into the corresponding three member 
    // variables of myClock. Therefore, an assignment statement 
    // performs a member-wise copy.

    cout << "*** After myClock = yourClock ;" << endl ;
    cout << "    myClock: " ;
    myClock.printTime() ;
    cout << endl ;

    cout << "  yourClock: " ;
    yourClock.printTime() ;
    cout << endl ;

    cout << "  &myClock: " << &myClock << endl ;
    cout << "&yourClock: " << &yourClock << endl ;

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

void clockType::printTime() const
{
    if (hr < 10)
        cout << "0" ;
    cout << hr << ":" ;

    if (min < 10)
        cout << "0" ;
    cout << min << ":" ;

    if (sec < 10)
        cout << "0" ;
    cout << sec ;
}

bool clockType::equalTime(const clockType& otherClock) const
{
    return (hr == otherClock.hr 
            && min == otherClock.min 
            && sec == otherClock.sec) ;
}
