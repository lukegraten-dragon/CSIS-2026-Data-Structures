/*
Inheritance

Suppose that you want to design the class partTimeEmployee to implement and
process the characteristics of a part-time employee. The main features associated
with a part-time employee are the name, pay rate, and number of hours worked. In
Example 10-10 (in Chapter 10), we designed a class to implement a person’s name.
Every part-time employee is a person. Therefore, rather than design the class
partTimeEmployee from scratch, we want to be able to extend the definition of the
class personType (from Example 10-10) by adding additional members (data and/
or functions).

Of course, we do not want to make the necessary changes directly to the class
personType—that is, edit the class personType and add and/or delete members.
In fact, we want to create the class partTimeEmployee without making any physical
changes to the class personType by adding only the members that are necessary.
For example, because the class personType already has members to store
the first name and last name, we will not include any such members in the class
partTimeEmployee. In fact, these member variables will be 'inherited' from the class
personType. (We will design such a class in Example 11-3.)

- Inheritance (“is-a” relationship)
- Composition (aggregation) (“has-a” relationship)

In Chapter 10, we extensively studied and designed the class clockType to implement
the time of day in a program. The class clockType has three member variables
to store the hours, minutes, and seconds. Certain applications, in addition to
the hours, minutes, and seconds, might also require us to store the time zone. In this
case, we would like to extend the definition of the class clockType and create the
class extClockType to accommodate this new information. That is, we want to
derive the class extClockType by adding a member variable—say, timeZone—and
the necessary member functions to manipulate the time (see Programming Exercise 1
at the end of this chapter). In C11, the mechanism that allows us to accomplish this
task is the principle of inheritance. Inheritance is an “is-a” relationship; for instance,
“every employee is a person.”

Inheritance lets us create new classes from existing classes. The new classes that we
create from the existing classes are called the 'derived classes'; the existing classes are
called the 'base classes'. The derived classes inherit the properties of the base classes.
So rather than create completely new classes from scratch, we can take advantage of
inheritance and reduce software development complexity.

Each derived class, in turn, can become a base class for a future derived class. Inheritance
can be either single inheritance or multiple inheritance. In 'single inheritance',
the derived class is derived from a single base class; in 'multiple inheritance', the
derived class is derived from more than one base class. This chapter concentrates on
single inheritance.

The general syntax of a derived class is:

class className: memberAccessSpecifier baseClassName
{
    member list
} ;

in which memberAccessSpecifier is public, protected, or private. When no
memberAccessSpecifier is specified, it is assumed to be a private inheritance.
(We will discuss protected inheritance later in this chapter.)

Suppose that we have defined a class called shape. The following statements specify
that the class circle is derived from shape, and it is a public inheritance.

class circle: public shape
{
.
.
.
} ;

On the other hand, consider the following definition of the class circle:

class circle: private shape
{
.
.
.
} ;

This is a private inheritance. In this definition, the public members of shape
become private members of the class circle. So any object of type circle cannot
directly access these members. The previous definition of circle is equivalent to:

class circle: shape
{
.
.
.
} ;

That is, if we do not use either the memberAccessSpecifier public or private, the
public members of a base class are inherited as private members by default.

The following facts about the base and the derived classes should be kept in mind.

1. The private members of a base class remain private to the base
   class; hence, the members of the derived class cannot directly access
   them. In other words, when you write the definitions of the member
   functions of the derived class, even though the private members of
   the base class are members of the derived class, the derived class cannot
   directly access them.

2. The public members of a base class can be inherited either as public
   members or as private members by the derived class. That is, the
   public members of the base class can become either public or
   private members of the derived class. This means that what were
   public members in the base class can either remain public members
   or become private members in the derived class.

3. The derived class can include additional members—data and/or
   functions.

4. The derived class can redefine the public member functions of
   the base class. That is, in the derived class, you can have a member
   function with the same name, number, and types of parameters as
   a function in the base class, but with different code in the function
   body. However, this redefinition applies only to the objects of the
   derived class, not to the objects of the base class.

5. All member variables of the base class are also member variables of
   the derived class. Similarly, the member functions of the base class
   (unless redefined) are also member functions of the derived class.
   (Remember Rule 1 when accessing a member of the base class in the
   derived class.)

*/


