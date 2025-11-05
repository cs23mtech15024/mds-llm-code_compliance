// Context: Allocation request handler

// Seed 090 — NC: function and parameter start with underscore
#include <iostream>
void* _allocate_memory(int _size) { // NC
    std::cout << "alloc=" << _size << " bytes\n";
    return nullptr;
}
int main(){
    _allocate_memory(1024);
    return 0;
}