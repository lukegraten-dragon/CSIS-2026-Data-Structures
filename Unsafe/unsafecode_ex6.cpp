#include <iostream>
#include <cstring>

void vulnerableFunction(const char* input) {
    char buffer[16]; // A small local array on the stack
    
    // Copying an input larger than 16 bytes overflows the buffer,
    // overwriting adjacent stack memory, including the stack canary.
    strcpy(buffer, input); 
    
    std::cout << "Data processed: " << buffer << std::endl;
}

int main() {
    // This string is 54 bytes long, well beyond the 16-byte buffer limit
    const char* unsafeInput = "This string is way too long and will smash the stack!";
    
    vulnerableFunction(unsafeInput);
    
    return 0;
}