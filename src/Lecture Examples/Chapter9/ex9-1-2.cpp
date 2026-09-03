// Record Assignment

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

    cout << "**** student" << endl
         << "First Name: " << student.firstName << endl
         << "Last Name : " << student.lastName << endl
         << "Course Grade: " << student.courseGrade << endl
         << "Test Score: " << student.testScore << endl
         << "Programming Score: " << student.programmingScore << endl
         << "GPA: " << student.GPA << endl << endl ;

    // student = newStudent ;
    // is equivalent to the following statements:
    // student.firstName = newStudent.firstName ;
    // student.lastName = newStudent.lastName ;
    // student.courseGrade = newStudent.courseGrade ;
    // student.testScore = newStudent.testScore ;
    // student.programmingScore = newStudent.programmingScore ;
    // student.GPA = newStudent.GPA ;

    // I would like to check if student = newStudent ; means student just points to newStudent.
    // It's a deep copy.
    student.testScore = 55 ;
    cout << "**** newStudent" << endl
         << "First Name: " << newStudent.firstName << endl
         << "Last Name : " << newStudent.lastName << endl
         << "Course Grade: " << newStudent.courseGrade << endl
         << "Test Score: " << newStudent.testScore << endl
         << "Programming Score: " << newStudent.programmingScore << endl
         << "GPA: " << newStudent.GPA << endl ;    

    return 0 ;
}