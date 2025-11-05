// Context: Moving average buffer index

// Seed 059 — C: variable without underscore prefix
#include <iostream>
int main(){
    int buffer_index = 0; // C
    buffer_index = (buffer_index + 1) % 10;
    std::cout << "idx=" << buffer_index << "\n";
    return 0;
}