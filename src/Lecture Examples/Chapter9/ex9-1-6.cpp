// structs in Arrays

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std ;

struct employeeType
{
    string firstName ;
    string lastName ;
    int personID ;
    string deptID ;
    double yearlySalary ;
    double monthlySalary ;
    double yearToDatePaid ;
    double monthlyBonus ;
} ;

int main()
{
    ifstream infile ;  //input file stream variable
    //ofstream outfile ; //output file stream variable

    const int num_of_employees = 10 ;
    employeeType employees[num_of_employees] ;

    infile.open("employees.txt") ;

    for (int i=0; i < num_of_employees; i++)
    {
        infile >> employees[i].firstName
               >> employees[i].lastName
               >> employees[i].personID
               >> employees[i].deptID
               >> employees[i].yearlySalary ;

        employees[i].monthlySalary = employees[i].yearlySalary / 12.0 ;
        employees[i].yearToDatePaid = 0.0 ;
        employees[i].monthlyBonus = 0.0 ;
    }

    double payCheck ; //variable to calculate the paycheck

    for (int i=0; i < num_of_employees; i++)
    //for (int counter = 0; counter < num_of_employees; counter++)
    {
        cout << left << setw(10)
             << employees[i].firstName << " "
             << left << setw(10)
             << employees[i].lastName << " " ;
        
        payCheck = employees[i].monthlySalary + employees[i].monthlyBonus ;
        employees[i].yearToDatePaid = employees[i].yearToDatePaid + payCheck ;

        cout << fixed << setprecision(2) << setw(10) << payCheck << endl ;
    }

    infile.close() ;
    //outfile.close() ;

    return 0 ;
}