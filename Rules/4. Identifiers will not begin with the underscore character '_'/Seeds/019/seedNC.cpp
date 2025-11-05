// Context: Data packet sequence number

// Seed 019 — NC: variable starts with underscore
#include <cstdint>
#include <iostream>
int main(){
    std::uint16_t _sequence_num = 1024; // NC
    _sequence_num++;
    std::cout << "seq=" << _sequence_num << "\n";
    return 0;
}