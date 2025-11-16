// Context: Cryptographic nonce generation

// ------ Non-Compliant Program (087_nc.cpp)
// Context: Cryptographic nonce generation (16 bytes)
// Rule: Array parameter decays to pointer (VIOLATION)
// Issue: Function could be called with any sized array
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <cstddef>

namespace crypto_087_nc {

static void fill_nonce(std::uint8_t *nonce, std::size_t n){ for(std::size_t i=0;i<n;i++){ nonce[i] = static_cast<std::uint8_t>((i*17)%256); } }

void generate_nonce(std::uint8_t nonce[]) { // NC API
    const std::size_t LEN = 16U; (void)LEN;
    fill_nonce(nonce, 16U);
    std::cout << std::hex << std::setfill('0');
    std::cout << "nonce0-3:";
    for(int i=0;i<4;i++){ std::cout << std::setw(2) << static_cast<int>(nonce[i]) << ' '; }
    std::cout << std::dec << "\n";
}

} // namespace crypto_087_nc

int main(){
    using namespace crypto_087_nc;
    std::uint8_t buf[16] = {0};
    generate_nonce(buf);
    return 0;
}
