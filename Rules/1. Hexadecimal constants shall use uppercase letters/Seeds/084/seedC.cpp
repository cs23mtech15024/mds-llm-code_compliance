// Context: DNS query response cache TTL value

// Seed 091 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t ttl=0x015180; // C (digits only)
    std::cout << "dns_ttl=" << ttl << "\n";
    return 0;
}