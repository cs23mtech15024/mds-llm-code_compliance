// Context: Encoder ring segment markers

// ------ Non-Compliant Program (083_nc.cpp)
// Context: Encoder ring segment markers (360 slots)
// Rule: Array parameter decays to pointer (VIOLATION)
// Issue: Callee cannot verify element count
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace enc_083_nc {

static std::uint16_t to_u16(int v){ return static_cast<std::uint16_t>(v); }

static void stamp_index(std::uint16_t *m, std::size_t n){ if(n>0U){ m[0] = 1024U; } }

void calibrate(std::uint16_t markers[]) { // NC API
    const std::size_t N = 360U; (void)N;
    stamp_index(markers, 360U);
    // simple checksum over the first 12 markers
    unsigned long sum = 0UL;
    for(int i=0;i<12;i++){ sum += markers[i]; }
    std::cout << "marker0=" << static_cast<int>(markers[0])
              << ", csum12=" << sum << "\n";
}

static void preview(const std::uint16_t *m){
    for(int i=0;i<8;i++){ std::cout << (i?",":"first:") << static_cast<int>(m[i]); }
    std::cout << "\n";
}

} // namespace enc_083_nc

int main(){
    using namespace enc_083_nc;
    std::uint16_t ring[360] = {};
    for(int i=0;i<360;i++){ ring[i] = to_u16((i*11)%2048); }
    calibrate(ring);
    preview(ring);
    return 0;
}
