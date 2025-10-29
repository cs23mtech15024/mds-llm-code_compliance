// Context: Timing tick denominator for sched loop

// Seed 020 — C: uppercase hex denominator
#include <iostream>
int main(){
    float dt = 1.0F/static_cast<float>(0x3E8); // C
    std::cout << "dt=" << dt << "\n";
    return 0;
}