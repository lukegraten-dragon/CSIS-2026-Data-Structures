/*
Destructors in a Derived Class

Recall from Chapter 10 that a class can have a destructor. As we will see in the next
chapter, destructors are typically used to deallocate dynamic memory allocated to the
objects of a class. (A memory space that is allocated during execution time is called
a dynamic memory space. The next chapter explains how to create and work with
dynamic memory.) Suppose that a base class and its derived class have destructors.
When a derived class object goes out of scope, it automatically invokes its destructor.
When the destructor of the derived class executes, it automatically invokes the destructor
of the base class. So when writing the definition of the destructor of the derived
class, an explicit call to the destructor of the base class is not needed. Furthermore,
when the destructor of the derived class executes, it executes its own code first and
then calls the destructor of the base class. For example, suppose that class three is
derived from class two, class two is derived from class one, and these classes have
destructors. When an object of class three goes out of scope, first the destructor
of class three executes, then the destructor of class two executes, and finally, the
destructor of class one executes. That is, the destructors execute in the reverse order.
*/