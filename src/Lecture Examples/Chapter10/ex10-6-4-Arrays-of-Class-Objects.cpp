// Arrays of Class Objects (Variables) and Constructors

#include <iostream>  

using namespace std ; 

// If a class has constructors and you declare an array of that 
// class’s objects, the class should have the default constructor. 
// The default constructor is typically used to initialize 
// each (array) class object.

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

    clockType() {}             // default constructor
    clockType(int, int, int) ; // constructor with parameters

private:
    int hr  = 5 ;
    int min = 18 ;
    int sec = 12 ;
} ;

int main()
{
    // For example, if you declare an array of 100 class objects, 
    // then it is impractical (if not impossible) to specify different 
    // constructors for each component. (We will further clarify this 
    // at the end of this section.)

    // Suppose that you have 100 employees who are paid on an hourly 
    // basis, and you need to keep track of their arrival and departure 
    // times. You can declare two arrays— arrivalTimeEmp and departureTimeEmp—of 
    // 100 components each, wherein each component is an object of type clockType.

    clockType arrivalTimeEmp[100] ;

    for (int j = 0; j < 100; j++)
    {
        cout << "Employee " << (j + 1) << " arrival time: ";
        arrivalTimeEmp[j].printTime() ;
        cout << endl ;
    }

    return 0 ;
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
