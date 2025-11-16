// Context: QR code module bitmap

// Seed 052 — C: QR bitmap by reference
#include <iostream>
#include <cstdint>
void generate_qr(std::uint8_t (&modules)[441]) { // C
    modules[0] = 1;
    std::cout << "module0=" << static_cast<int>(modules[0]) << "\n";
}
int main(){
    std::uint8_t qr_bitmap[441] = {0};
    generate_qr(qr_bitmap);
    return 0;
}