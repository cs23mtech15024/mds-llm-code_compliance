// Context: TLS handshake mask for retry path

// Seed 032 — C: uppercase hex mask
#include <iostream>
int main(){
    float baseTimeout=0.5F; unsigned retries=3U; (void)baseTimeout; (void)retries;
    unsigned mask=0xFF; // C
    std::cout << "tls_mask=0x" << std::hex << mask << "\n";
    return 0;
}