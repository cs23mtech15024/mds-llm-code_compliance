// Context: Sampler interval literal tag (engine)

// Seed 047 — C: uppercase hex in interval
#include <iostream>
int main(){
    unsigned interval=0x3C; // C
    std::cout << "engine_interval=" << std::dec << interval << "\n";
    return 0;
}