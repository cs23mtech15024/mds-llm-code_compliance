// Context: RFID tag identifier storage

// ------ Compliant Program (044_c.cpp)
// Context: Write first RFID tag slot and pretty-print
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <cstdint>
#include <iomanip>

namespace rfid_044_c {

static void write_head(std::uint32_t (&tag_ids)[50], std::uint32_t v) {
    tag_ids[0] = v;
}

void store_tag_id(std::uint32_t (&tag_ids)[50]) { // C API
    write_head(tag_ids, 0x12345678U);
    std::cout << "tag0=0x" << std::hex << std::uppercase << tag_ids[0] << "\n";
}

} // namespace rfid_044_c

int main() {
    using namespace rfid_044_c;
    std::uint32_t rfid_tags[50] = {0};
    store_tag_id(rfid_tags);
    return 0;
}
