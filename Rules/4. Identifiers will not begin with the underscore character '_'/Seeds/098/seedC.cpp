// Context: Stack size allocator

// Seed 098 — C: function and parameter without underscore prefix
#include <iostream>
void allocate_stack(int size_kb) { // C
    std::cout << "stack=" << size_kb << "KB\n";
}
int main(){
    allocate_stack(64);
    return 0;
}