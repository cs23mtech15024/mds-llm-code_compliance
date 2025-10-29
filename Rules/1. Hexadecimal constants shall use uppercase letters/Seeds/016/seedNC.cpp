// Context: Timing tick denominator for sched loop

// Seed 020 — NC: lowercase hex denominator
#include <iostream>
int main(){
    float dt = 1.0F/static_cast<float>(0x3e8); // NC
    std::cout << "dt=" << dt << "\n";
    return 0;
}