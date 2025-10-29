// Context: OAuth token expiration timestamp offset

// Seed 092 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint32_t exp=0xe10; // NC: 3600s (1 hour)
    std::cout << "oauth_exp=" << exp << "\n";
    return 0;
}