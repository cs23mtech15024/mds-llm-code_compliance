// Context: Battery sim step-count literal tag

// Seed 045 — NC: lowercase hex in step count
#include <iostream>
int main(){
    unsigned steps=0x0a; // NC: 10
    std::cout << "sim_steps=" << steps << "\n";
    return 0;
}