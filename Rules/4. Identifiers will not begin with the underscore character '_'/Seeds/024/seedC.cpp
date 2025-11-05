// Context: Buffer allocation size

// Seed 024 — C: variable without underscore prefix
#include <iostream>
int main(){
    int buffer_size = 512; // C
    std::cout << "alloc=" << buffer_size << " bytes\n";
    return 0;
}