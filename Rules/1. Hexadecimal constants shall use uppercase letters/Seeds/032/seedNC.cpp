// Context: Sampler interval literal tag (engine)

// Seed 047 — NC: lowercase hex in interval
#include <iostream>
int main(){
    unsigned interval=0x3c; // NC: 60
    std::cout << "engine_interval=" << std::dec << interval << "\n";
    return 0;
}