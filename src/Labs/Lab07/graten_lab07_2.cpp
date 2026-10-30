/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 07 Part 1
// Date Modified: 10-30-2026
// AI Models Used: No AI Used
//
/******************************************************/

#include <iostream>
using namespace std ;

void fill(int *pointer, int students, int subjects)
{
    for (int stu = 0 ; stu < students ; stu++)
    {
        cout << "Enter the scores for student "
            << stu + 1 << ": " ;
        
        for (int sub = 0 ; sub < subjects ; sub++)
        {
            cin >> pointer[stu * subjects + sub] ;
        }
        cout << '\n' ;
    }
}

void print(int *pointer, int students, int subjects)
{
    for (int stu = 0 ; stu < students ; stu++)
    {
        cout << "Student " << stu + 1 << ": " ;

        for (int sub = 0 ; sub < subjects ; sub++)
        {
            cout << pointer[stu * subjects + sub] << " " ;
        }
        cout << '\n' ;
    }
}

int main()
{
    int *scores ; // Declare pointer
    int students = 0 ;
    int subjects = 0 ;

    // Ask for students and subjects
    cout << "Enter the number of students: " ;
    cin >> students ;
    cout << "Enter the number of subjects: " ;
    cin >> subjects ;
    cout << '\n' ;

    // Allocate memory for our 2D array
    scores = new int[students * subjects] ;

    // Fill up the array
    fill(scores, students, subjects) ;

    // Print the scores
    cout << "Scores Table:" << '\n' ;
    print(scores, students, subjects) ;

    // Delete and set as nullptr.
    delete scores ;
    scores = nullptr ;

    return 0 ;
}