// Records (structs)

#include <iostream>

using namespace std ;

struct houseType
{
    string style ;
    int numOfBedrooms ;
    int numOfBathrooms ;
    int numOfCarsGarage ;
    int yearBuilt ;
    int finishedSquareFootage ;
    double price ;
    double tax ;
} ;

int main()
{
    houseType ryanHouse ;
    houseType anitaHouse ;

    ryanHouse.style = "Colonial" ;
    ryanHouse.numOfBedrooms = 3 ;
    ryanHouse.numOfBathrooms = 2 ;
    ryanHouse.numOfCarsGarage = 2 ;
    ryanHouse.yearBuilt = 2005 ;
    ryanHouse.finishedSquareFootage = 2250 ;
    ryanHouse.price = 290000 ;
    ryanHouse.tax = 5000.50 ;

    cout << "**** Ryan's House" << endl
         << "House Style: " << ryanHouse.style << endl
         << "Num of Bedrooms: " << ryanHouse.numOfBedrooms << endl
         << "Num of Bathrooms: " << ryanHouse.numOfBathrooms << endl
         << "Num of CarsGarage: " << ryanHouse.numOfCarsGarage << endl
         << "Year Built: " << ryanHouse.yearBuilt << endl
         << "Finished Square Footage: " << ryanHouse.finishedSquareFootage << endl
         << "Price: " << ryanHouse.price << endl
         << "Tax: " << ryanHouse.tax << endl << endl ;

    // Ranch 4 350000
    cin >> anitaHouse.style >> anitaHouse.numOfBedrooms
        >> anitaHouse.price;

    cout << "**** Anita's House" << endl
         << "House Style: " << anitaHouse.style << endl
         << "Num of Bedrooms: " << anitaHouse.numOfBedrooms << endl
         << "Price: " << anitaHouse.price << endl ;

    return 0 ;
}