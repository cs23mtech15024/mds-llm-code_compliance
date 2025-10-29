// Context: Path planner hex-suffix & mask

// Seed 100 — NC: lowercase 'x'/'u' style & mask
#include <iostream>
int main(){
    unsigned H = 0x1234u; // NC: lowercase suffix/prefix style
    unsigned M = 0xff;    // NC
    std::cout<<"H=0x"<<std::hex<<H<<" M=0x"<<M<<"\n";
    return 0;
}