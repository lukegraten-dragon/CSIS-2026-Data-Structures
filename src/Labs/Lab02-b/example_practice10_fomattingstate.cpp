#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a = 125.75;
    double b = 24.5;
    
    cout << scientific << setprecision(2);
    cout << a << endl;
    cout << b << endl;

    return 0;
}

/*
Many formatting manipulators are "sticky"
meaning they remain enabled unless explicitly
disabled via unsetf().

Its super important to think about the current formatting
manipulators that are active when printing things
in succession.
*/