#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std ;

int main()
{
    ifstream inFile ;  //input file stream variable
    ofstream outFile ; //output file stream variable

    inFile.open("ex5-25.txt") ;

    int ID ;
    string name ;
    int num ;

    int sum ;
    char ch ;

    inFile >> ID ;              //Line 1; //read the ID

    while (inFile)              //Line 2
    {                           //Line 3
        inFile.get(ch) ;        //Line 4; //read the newline character after the ID
        getline(inFile, name);  //Line 5; //read the name

        sum = 0;                //Line 6
        inFile >> num ;         //Line 7; read the first number
        while (num != -999)     //Line 8
        { //Line 9
            sum = sum + num ;   //Line 10; update sum
            inFile >> num ;     //Line 11; read the next number
        }
        cout << "Name: " << setw(13) << name
             << ", Votes: " << sum
             << endl ;          //Line 12
        inFile >> ID ;          //Line 13; begin processing the next line
    }

    inFile.close() ;
    
    return 0 ;
}