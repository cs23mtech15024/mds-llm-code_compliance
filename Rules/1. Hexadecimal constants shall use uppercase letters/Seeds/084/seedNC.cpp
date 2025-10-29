// Context: DNS query response cache TTL value

// Seed 091 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t ttl=0x015180; // NC: 86400s (24h)
    std::cout << "dns_ttl=" << ttl << "\n";
    return 0;
}