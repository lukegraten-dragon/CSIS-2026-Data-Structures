#include <iostream>

using namespace std ;

int secret(int x) ;

int main()
{
    int num = 10 ;
    cout << "secret(" << num << "): " << secret(num) << endl ;

    return 0 ;
}

int secret(int x)
{
    if (x > 5)
        return 2 * x ;
    //return x ;
}