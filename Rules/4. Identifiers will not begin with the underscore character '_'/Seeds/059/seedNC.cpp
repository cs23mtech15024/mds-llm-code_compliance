// Context: Moving average buffer index

// Seed 059 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _buffer_index = 0; // NC
    _buffer_index = (_buffer_index + 1) % 10;
    std::cout << "idx=" << _buffer_index << "\n";
    return 0;
}