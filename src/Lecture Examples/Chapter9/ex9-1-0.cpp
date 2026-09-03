// Records (structs)

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

    newStudent.firstName = "John" ;
    newStudent.lastName = "Brown" ;
    newStudent.courseGrade ;
    newStudent.testScore = 100 ;
    newStudent.programmingScore = 95 ;
    newStudent.GPA = 4.3 ;
    
    if (newStudent.testScore >= 90)
        newStudent.courseGrade = 'A' ;
    else if (newStudent.testScore >= 80)
        newStudent.courseGrade = 'B' ;
    else if (newStudent.testScore >= 70)
        newStudent.courseGrade = 'C' ;
    else if (newStudent.testScore >= 60)
        newStudent.courseGrade = 'D' ;
    else
        newStudent.courseGrade = 'F' ;

    cout << "First Name: " << newStudent.firstName << endl
         << "Last Name : " << newStudent.lastName << endl
         << "Course Grade: " << newStudent.courseGrade << endl
         << "Programming Score: " << newStudent.programmingScore << endl
         << "GPA: " << newStudent.GPA << endl ;

    return 0 ;
}