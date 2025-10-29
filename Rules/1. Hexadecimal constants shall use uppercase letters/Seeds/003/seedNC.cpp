// Context: Hash salt constant for consistent sharding

// Seed 004 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    const std::uint64_t SALT=0x9e3779b97f4a7c15ULL; // NC
    std::uint64_t h = 0U ^ (123U + SALT + (0U<<6) + (0U>>2));
    std::cout << "hash=0x" << std::hex << h << "\n";
    return 0;
}