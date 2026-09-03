#include <iostream>

class IntStack {
private:
    int capacity; // Member variable

public:
    IntStack(int capacity) { // Parameter 'capacity' shadows the member variable
        // Bug: This assigns the parameter to itself, 
        // leaving the member variable 'capacity' uninitialized.
        capacity = capacity; 
    }
};