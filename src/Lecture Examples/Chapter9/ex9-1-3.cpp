// Record Comparison (Relational Operators)

#include <iostream>

using namespace std ;

struct studentType
{
    string firstName ;
    string lastName ;
    char courseGrade ;
    int testScore ;
    int programmingScore ;
    double GPA ;
} ;

int main()
{
    // record variable
    studentType newStudent ;
    studentType student ;

    newStudent.firstName = "Lisa" ;
    newStudent.lastName = "Robinson" ;
    newStudent.courseGrade = 'A' ;
    newStudent.testScore = 95 ;
    newStudent.programmingScore = 98 ;
    newStudent.GPA = 3.9 ;

    // copies the contents of newStudent into student.
    student = newStudent ;

    if (student.firstName == newStudent.firstName &&
        student.lastName == newStudent.lastName)
    {
        cout << "student's first name and last name are equal to those of newStudent" << endl ;
    } 
    else {
        cout << "student's first name and last name are NOT equal to those of newStudent" << endl ;
    }

    return 0 ;
}