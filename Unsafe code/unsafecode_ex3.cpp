#include <iostream>

int main() {
    int* ptr = new int(100);

    // First deletion is correct
    delete ptr;

    // Double free: deleting the same memory pointer a second time
    delete ptr;

    return 0;
}
