// Context: Allocation request handler

// Seed 090 — C: function and parameter without underscore prefix
#include <iostream>
void* allocate_memory(int size) { // C
    std::cout << "alloc=" << size << " bytes\n";
    return nullptr;
}
int main(){
    allocate_memory(1024);
    return 0;
}