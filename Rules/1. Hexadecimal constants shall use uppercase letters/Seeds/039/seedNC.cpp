// Context: Autopilot heading correction literal

// Seed 059 — NC: lowercase-style hex correction
#include <iostream>
int main(){
    long corr=0x7; // NC: 7
    std::cout << "hdg_corr=0x" << std::hex << corr << "\n";
    return 0;
}