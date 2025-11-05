// Context: Data packet sequence number

// Seed 019 — C: variable without underscore prefix
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t sequence_num = 1024; // C
    sequence_num++;
    std::cout << "seq=" << sequence_num << "\n";
    return 0;
}