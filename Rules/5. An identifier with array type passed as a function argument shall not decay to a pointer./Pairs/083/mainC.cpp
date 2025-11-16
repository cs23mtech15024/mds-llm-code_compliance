// Context: Encoder ring segment markers

// ------ Compliant Program (083_c.cpp)
// Context: Encoder ring segment markers (360 slots)
// Status: Array passed by reference (COMPLIANT)
// Advantage: Prevents wrong-size buffers at compile time
#include <iostream>
#include <cstdint>

namespace enc_083_c {

static std::uint16_t to_u16(int v){ return static_cast<std::uint16_t>(v); }

static void stamp_index(std::uint16_t (&m)[360]){ m[0] = 1024U; }

void calibrate(std::uint16_t (&markers)[360]) { // C API
    stamp_index(markers);
    unsigned long sum = 0UL;
    for(int i=0;i<12;i++){ sum += markers[i]; }
    std::cout << "marker0=" << static_cast<int>(markers[0])
              << ", csum12=" << sum << "\n";
}

static void preview(const std::uint16_t (&m)[360]){
    for(int i=0;i<8;i++){ std::cout << (i?",":"first:") << static_cast<int>(m[i]); }
    std::cout << "\n";
}

} // namespace enc_083_c

int main(){
    using namespace enc_083_c;
    std::uint16_t ring[360] = {};
    for(int i=0;i<360;i++){ ring[i] = to_u16((i*11)%2048); }
    calibrate(ring);
    preview(ring);
    return 0;
}
