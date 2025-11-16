// Context: Cryptographic nonce generation

// ------ Compliant Program (087_c.cpp)
// Context: Cryptographic nonce generation (16 bytes)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Compiler enforces 16-byte nonce buffer
#include <iostream>
#include <iomanip>
#include <cstdint>

namespace crypto_087_c {

static void fill_nonce(std::uint8_t (&nonce)[16]){ for(std::size_t i=0;i<16U;i++){ nonce[i] = static_cast<std::uint8_t>((i*17)%256); } }

void generate_nonce(std::uint8_t (&nonce)[16]) { // C API
    fill_nonce(nonce);
    std::cout << std::hex << std::setfill('0');
    std::cout << "nonce0-3:";
    for(int i=0;i<4;i++){ std::cout << std::setw(2) << static_cast<int>(nonce[i]) << ' '; }
    std::cout << std::dec << "\n";
}

} // namespace crypto_087_c

int main(){
    using namespace crypto_087_c;
    std::uint8_t buf[16] = {0};
    generate_nonce(buf);
    return 0;
}
