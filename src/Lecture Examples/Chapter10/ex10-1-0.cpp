// Variable (Object) Declaration and Accessing Class Members

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

    myClock.setTime(5, 2, 30) ;
    myClock.printTime() ;
    cout << endl ;
    yourClock.setTime(x, y, z) ;

    // In the fourth statement, the member function equalTime executes and compares
    // the three member variables of myClock to the corresponding member variables of
    // yourClock. Because in this statement equalTime is a member of the object myClock,
    // it has direct access to the three member variables of myClock. So it needs one more
    // object, which in this case is yourClock, to compare. In essence, equalTime needs
    // two objects to compare. The object to which it is dotted, myClock, is one and the
    // argument, yourClock, is the other. This explains why the function equalTime has
    // only one parameter.
    if (myClock.equalTime(yourClock))
    {
        
    }

    // The objects myClock and yourClock can access only public members of 
    // the class clockType. Thus, the following statements are illegal 
    // because hr and min are declared as private members of the class clockType 
    // and, therefore, cannot be accessed by the objects myClock and yourClock:
    // myClock.hr = 10; //illegal
    // myClock.min = yourClock.min; //illegal

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

