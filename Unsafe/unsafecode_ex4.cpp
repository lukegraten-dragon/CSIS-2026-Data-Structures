/*
#include <iostream>

void setCapacity(int capacity) {
    std::cout << "Capacity set to: " << capacity << "\n";
}

int main() {
    long long largeNumber = 5000000000LL; // Exceeds the maximum value of a 32-bit int
    
    // -Wconversion catches this implicit narrowing conversion
    setCapacity(largeNumber); 

    return 0;
}
*/