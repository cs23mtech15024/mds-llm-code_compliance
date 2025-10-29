// Context: Hash salt constant for consistent sharding

// Seed 004 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    const std::uint64_t SALT=0x9E3779B97F4A7C15ULL; // C
    std::uint64_t h = 0U ^ (123U + SALT + (0U<<6) + (0U>>2));
    std::cout << "hash=0x" << std::hex << h << "\n";
    return 0;
}