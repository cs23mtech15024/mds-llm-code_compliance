// Context: Hover offset literal

// Seed 066 — NC: lowercase hex hover offset
#include <iostream>
int main(){
    long offset = 0x0d; // NC: 13
    float err = 0.33F; (void)err;
    std::cout << "hover_offset=" << offset << "\n";
    return 0;
}