// Context: Forklift ref height literal

// Seed 075 — NC: lowercase hex reference height
#include <iostream>
int main(){
    long ref = 0x1b; // NC: 27
    float g = 0.8F; (void)g;
    std::cout << "fork_ref_h=" << ref << "\n";
    return 0;
}