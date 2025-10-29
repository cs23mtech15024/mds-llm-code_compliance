// Context: Torque control ID literal

// Seed 057 — NC: lowercase-style hex control ID
#include <iostream>
int main(){
    long id=0x65; // NC: 101
    std::cout << "torque_id=0x" << std::hex << id << "\n";
    return 0;
}