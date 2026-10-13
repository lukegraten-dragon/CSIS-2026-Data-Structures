// Records (structs)

#include <iostream>

using namespace std ;

// Struct is a custom programmer-defined data structure, like a container that can have variables inside it
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

    newStudent.firstName = "John" ; // Define each 'part' of the newStudent studentType struct instance
    newStudent.lastName = "Brown" ;
    newStudent.courseGrade ;
    newStudent.testScore = 100 ;
    newStudent.programmingScore = 95 ;
    newStudent.GPA = 4.3 ;
    
    if (newStudent.testScore >= 90) // Use if statement to select lettergrade based off instance courseGrade
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