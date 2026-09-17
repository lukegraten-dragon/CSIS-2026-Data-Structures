# include <iostream>
using namespace std ;

// This code is buggy (has a semantic error) and is
// used purely as a reference. DO NOT SUBMIT THIS FILE.

int main() 
{   
    double score ;

    cout << "Enter the score (0-100): " ;
    cin >> score ;
    cout << endl ;

    if (score >= 50.0)
        if (score >= 90.0)
            cout << "Excellent." << endl ;
    else
        cout << "Fail." << endl ;

    return 0 ;
}