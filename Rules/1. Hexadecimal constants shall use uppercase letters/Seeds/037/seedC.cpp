// Context: Torque control ID literal

// Seed 057 — C: uppercase prefix style hex control ID
#include <iostream>
int main(){
    long id=0X65; // C: uppercase 'X'
    std::cout << "torque_id=0x" << std::hex << id << "\n";
    return 0;
}