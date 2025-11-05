// Context: Circular buffer write pointer

// Seed 062 — NC: variable starts with underscore
#include <iostream>
int main(){
    int _write_ptr = 0; // NC
    _write_ptr++;
    std::cout << "wr_ptr=" << _write_ptr << "\n";
    return 0;
}