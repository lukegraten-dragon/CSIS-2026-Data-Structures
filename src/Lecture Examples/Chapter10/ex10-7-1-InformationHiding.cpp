// Information Hiding

/*
The previous section defined the class clockType to implement the time in a program.
We then wrote a program that used the class clockType. In fact, we combined
the class clockType with the function definitions to implement the operations
and the function main so as to complete the program. That is, the specification and
implementation details of the class clockType were directly incorporated into the
program.
Is it a good practice to include the specification and implementation details of a class
in the program? Definitely not. There are several reasons for not doing so. Suppose
the definition of the class and the definitions of the member functions are directly
included in the user’s program. The user then has direct access to the definition of
the class and the definitions of the member functions. Therefore, the user can modify
the operations in any way the user pleases. The user can also modify the member
variables of an object in any way the user pleases. Thus, in this sense, the private
member variables of an object are no longer private to the object.
If several programmers use the same object in a project and if they have direct access
to the internal parts of the object, there is no guarantee that every programmer will
use the same object in exactly the same way. Thus, we must hide the implementation
details. The user should know only what the object does, not how it does it. Hiding
the implementation details frees the user from having to fit this extra piece of code in
the program. Also, by hiding the details, we can ensure that an object will be used in
exactly the same way throughout the project. Furthermore, once an object ha
*/

int main () 
{

    return 0 ;
}

