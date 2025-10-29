// Context: Rail temp reference literal

// Seed 062 — NC: lowercase hex rail temperature reference
#include <iostream>
int main(){
    long refTemp = 0x10a; // NC: 266
    float gain = 0.45F; (void)gain;
    std::cout << "rail_ref_temp=0x" << std::hex << refTemp << "\n";
    return 0;
}