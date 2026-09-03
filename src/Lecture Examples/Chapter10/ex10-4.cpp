class clockType
{
private:
    int hr ;
    int min ;
    int sec ;
public:
    void setTime(int, int, int) ;
    void getTime(int&, int&, int&) const ;
    void printTime() const ;
    void incrementSeconds() ;
    void incrementMinutes() ;
    void incrementHours() ;
    bool equalTime(const clockType&) const ;
} ;

int main()
{
    return 0 ;
}