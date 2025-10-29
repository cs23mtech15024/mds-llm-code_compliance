// Context: QR error-correction mask selector

// Seed 034 — C: uppercase hex mask
#include <iostream>
int main(){
    unsigned ecMask=0x00FF; // C
    unsigned level=2U; (void)level;
    std::cout << "qr_mask=0x" << std::hex << ecMask << "\n";
    return 0;
}