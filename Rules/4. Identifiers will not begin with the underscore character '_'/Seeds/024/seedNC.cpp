// Context: Buffer allocation size

// Seed 024 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _buffer_size = 512; // NC
    std::cout << "alloc=" << _buffer_size << " bytes\n";
    return 0;
}