// Context: Circular buffer write pointer

// Seed 062 — C: variable without underscore prefix
#include <iostream>
int main(){
    int write_ptr = 0; // C
    write_ptr++;
    std::cout << "wr_ptr=" << write_ptr << "\n";
    return 0;
}