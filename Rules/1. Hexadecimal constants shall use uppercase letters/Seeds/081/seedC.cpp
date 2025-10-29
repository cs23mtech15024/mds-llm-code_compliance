// Context: OAuth token expiration timestamp offset

// Seed 092 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t exp=0xE10; // C
    std::cout << "oauth_exp=" << exp << "\n";
    return 0;
}