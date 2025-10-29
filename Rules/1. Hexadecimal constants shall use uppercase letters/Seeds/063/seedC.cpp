// Context: Path planner hex-suffix & mask

// Seed 100 — C: uppercase 'X'/'U' style & mask
#include <iostream>
int main(){
    unsigned H = 0X1234U; // C
    unsigned M = 0xFF;    // C
    std::cout<<"H=0x"<<std::hex<<H<<" M=0x"<<M<<"\n";
    return 0;
}