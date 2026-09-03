// Record Variables and Functions

// Recall that a function cannot return a value of type array. However:
// - A struct variable can be passed as a parameter either by value 
//   or by reference, and
// - A function can return a value of type struct.

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

void readIn(studentType& student) ; // What if pass by value? Test it!!!
void printStudent(studentType student) ;

int main()
{
    // record variable
    studentType student ;

    // Lisa Robinson 98 95 4.3
    readIn(student) ;
    printStudent(student) ;

    return 0 ;
}

void readIn(studentType& student)
{
    int score ;

    cin >> student.firstName >> student.lastName ;
    cin >> student.testScore >> student.programmingScore ;
    cin >> student.GPA ;
    
    score = (student.testScore + student.programmingScore) / 2 ;

    if (score >= 90)
        student.courseGrade = 'A';
    else if (score >= 80)
        student.courseGrade = 'B';
    else if (score >= 70)
        student.courseGrade = 'C';
    else if (score >= 60)
        student.courseGrade = 'D';
    else
        student.courseGrade = 'F';
}

void printStudent(studentType student)
{
    cout << student.firstName << " " << student.lastName
         << " " << student.courseGrade
         << " " << student.testScore
         << " " << student.programmingScore
         << " " << student.GPA << endl ;
}
