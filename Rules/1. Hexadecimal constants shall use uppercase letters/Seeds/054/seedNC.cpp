// Context: Grid droop key literal

// Seed 079 — NC: lowercase hex key literal
#include <iostream>
int main(){
    long key = 0x6d; // NC: 109
    float droop = 3.3F; (void)droop;
    std::cout << "grid_key=0x" << std::hex << key << "\n";
    return 0;
}