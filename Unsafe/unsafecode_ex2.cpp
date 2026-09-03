#include <iostream>

int main() {
    int* ptr = new int(42);

    // Free the allocated memory
    delete ptr;

    // Use-after-free: reading from memory that has already been released
    std::cout << "Value after free: " << *ptr << "\n";

    return 0;
}