// Pointers and Arrays

#include <iostream>

using namespace std ;

int strlen(char *s) ;  // strlen: return length of string s
void f (int arr[]) ;
void g (int *arr) ;

int main()
{
    // When an array name is passed to a function, what is passed is the location of the initial
    // element. Within the called function, this argument is a local variable, and so an array name
    // parameter is a pointer, that is, a variable containing an address. We can use this fact to write
    // another version of strlen, which computes the length of a string.
    //
    // Since s is a pointer, incrementing it is perfectly legal; s++ has no effect on the character string
    // in the function that called strlen, but merely increments strlen's private copy of the
    // pointer. That means that calls like
    char array[] = {'a', 'b', 'c', 'd', 'e', 'f'} ;
    char *ptr = "CSIS 255" ;

    cout << "strlen(\"hello, world\"): " << strlen("hello, world") << endl ;  /* string constant */
    cout << "strlen(array): " << strlen(array) << endl ;                      /* char array[] ; */
    cout << "strlen(ptr): " << strlen(ptr) << endl ;                          /* char *ptr ; */
    // all work.

    // As formal parameters in a function definition,
    char s[] = {'h', 'e', 'l', 'l', 'o'} ;
    cout << s << endl ;
    // and
    // char *s  = "hello" ;
    // cout << s << endl ;
    // are equivalent; we prefer the latter because it says more explicitly that the variable is a
    // pointer. When an array name is passed to a function, the function can at its convenience
    // believe that it has been handed either an array or a pointer, and manipulate it accordingly. 
    // It can even use both notations if it seems appropriate and clear.

    // It is possible to pass part of an array to a function, by passing a pointer to the beginning of the
    // subarray. For example, if a is an array,
    int a[] = {2, 1, 9, 5, 1, 8} ;

    f(&a[2]) ;
    // and
    f(a+2) ;
    // both pass to the function f the address of the subarray that starts at a[2]. Within f, the
    // parameter declaration can read
    // f(int arr[]) { ... }
    // or
    // f(int *arr) { ... }
    // 
    // So as far as f is concerned, the fact that the parameter refers to part of a larger array is of no
    // consequence.

    return 0 ;
}

/* strlen: return length of string s */
int strlen(char *s)
{
    int n ;

    for (n = 0; *s != '\0'; s++)
        n++ ;
    
    return n ;
}

void f (int arr[])
{
    cout << arr << endl ;
}

void g (int *arr)
{
    cout << arr << endl ;
}
