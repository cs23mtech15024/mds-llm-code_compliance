// Context: Stack size allocator

// Seed 098 — NC: function and parameter start with underscore
#include <iostream>
void _allocate_stack(int _size_kb) { // NC
    std::cout << "stack=" << _size_kb << "KB\n";
}
int main(){
    _allocate_stack(64);
    return 0;
}