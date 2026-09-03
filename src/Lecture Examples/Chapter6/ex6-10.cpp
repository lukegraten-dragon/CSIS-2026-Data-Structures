// Call by Value and Call by Reference
#include <iostream>

using namespace std ;

void averageAndGrade(int testScore, int progScore,
                     double& average, char& grade) ;

int main()
{
    int testScore = 88 ; 
    int progScore = 94 ;
    double average = 2 ; 
    char grade = 'F' ;

    cout << "Before calling areaAndPerimeter()" << endl 
         << "testScore = " << testScore << endl
         << "progScore = " << progScore << endl
         << "average = " << average << endl         
         << "grade = " << grade << endl << endl ;

    averageAndGrade(testScore, progScore, average, grade) ;

    cout << "After calling areaAndPerimeter()" << endl 
         << "testScore = " << testScore << endl
         << "progScore = " << progScore << endl
         << "average = " << average << endl         
         << "grade = " << grade << endl << endl ;

    return 0 ;
}

void averageAndGrade(int testScore, int progScore,
                     double& average, char& grade)
{
    average = (testScore + progScore) / 2.0 ;
    
    if (average >= 90.00)
        grade = 'A' ;
    else if (average >= 80.00)
        grade = 'B' ;
    else if (average >= 70.00)
        grade = 'C' ;
    else if (average >= 60.00)
        grade = 'D' ;
    else
        grade = 'F' ;
}