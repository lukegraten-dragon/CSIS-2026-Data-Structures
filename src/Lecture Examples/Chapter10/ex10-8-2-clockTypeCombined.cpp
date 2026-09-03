// This example is based on the ex10-7-3 files.
// However, in this version, we combine all the code into a single .cpp file.

#include <iostream>
  
using namespace std ; 

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
    clockType(int hours, int minutes, int seconds) ;
    clockType() ;

private:
    int hr ;  //variable to store the hours
    int min ; //variable to store the minutes
    int sec ; //variable to store the seconds
} ;

int main()
{
    clockType myClock ;
    clockType yourClock ;  

    int hours ;
    int minutes ;
    int seconds ;

    myClock.setTime(5, 4, 30) ;                         //Line 1

    cout << "Line 2: myClock: " ;                       //Line 2
    myClock.printTime() ;  //print the time of myClock    Line 3
    cout << endl ;                                      //Line 4

    cout << "Line 5: yourClock: " ;                     //Line 5
    yourClock.printTime() ; //print the time of yourClock Line 6
    cout << endl ;                                      //Line 7

    yourClock.setTime(5, 45, 16) ;                      //Line 8

    cout << "Line 9: After setting, yourClock: " ;      //Line 9
    yourClock.printTime() ; //print the time of yourClock Line 10
    cout << endl ;                                      //Line 11

    if (myClock.equalTime(yourClock))                   //Line 12
        cout << "Line 13: Both times are equal."
             << endl ;                                  //Line 13
    else                                                //Line 14
        cout << "Line 15: The two times are not equal."
             << endl ;                                  //Line 15

    cout << "Line 16: Enter the hours, minutes, and "
         << "seconds: " ;                               //Line 16
    cin >> hours >> minutes >> seconds ;                //Line 17
    cout << endl ;                                      //Line 18

    myClock.setTime(hours, minutes, seconds) ;          //Line 19

    cout << "Line 20: New myClock: " ;                  //Line 20
    myClock.printTime() ;   //print the time of myClock   Line 21
    cout << endl ;                                      //Line 22

    myClock.incrementSeconds() ;                        //Line 23

    cout << "Line 24: After incrementing myClock by " 
         << "one second, myClock: " ;                   //Line 24
    myClock.printTime() ;   //print the time of myClock   Line 25
    cout << endl ;                                      //Line 26

    myClock.getTime(hours, minutes, seconds) ;          //Line 27

    cout << "Line 28: hours = " << hours 
         << ", minutes = " << minutes 
         << ", seconds = " << seconds << endl ;         //Line 28

    return 0 ;
}//end main


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

void clockType::getTime(int& hours, int& minutes, int& seconds) const
{
    hours = hr ;
    minutes = min ;
    seconds = sec ;
}

void clockType::incrementHours()
{
    hr++ ;
    if (hr > 23)
        hr = 0 ;
}

void clockType::incrementMinutes()
{
    min++ ;
    if (min > 59)
    {
        min = 0 ;
        incrementHours() ;
    }
}

void clockType::incrementSeconds()
{
    sec++ ;

    if (sec > 59)
    {
        sec = 0 ;
        incrementMinutes() ;
    }
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

clockType::clockType()  //default constructor
{
    hr = 0 ;
    min = 0 ;
    sec = 0 ;
}
