// This declaration is the same as before. 
// For the sake of completeness, we include the class definition:

// C++ has no fixed order in which you declare public and private members; 
// you can declare them in any order. The only thing you need to remember 
// is that, by default, all members of a class are 'private'.
//
// You must use the member access specifier public to make a member available 
// for public access. Member access remains as set for all declared members 
// until explicitly reset, so public sets all members public until explicitly 
// changed to private. Therefore, if you decide to declare the private members 
// after the public members (as is done in the case of clockType), you must 
// use the member access specifier private to begin the declaration of the 
// private members. 
//
// We can declare the class clockType in one of three ways, as shown in 
// Examples 10-3 through 10-5.

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
    return 0 ;
}