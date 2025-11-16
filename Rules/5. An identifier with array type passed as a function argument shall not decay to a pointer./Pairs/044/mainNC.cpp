// Context: RFID tag identifier storage

// ------ Non-Compliant Program (044_nc.cpp)
// Context: Write first RFID tag slot and pretty-print
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <cstddef>

namespace rfid_044_nc {

// NC helper: pointer + length, no compile-time extent
static void write_head(std::uint32_t *tag_ids, std::size_t n, std::uint32_t v) {
    if (n > 0U) tag_ids[0] = v;
}

void store_tag_id(std::uint32_t tag_ids[]) { // NC API
    write_head(tag_ids, 50U, 0x12345678U);
    std::cout << "tag0=0x" << std::hex << std::uppercase << tag_ids[0] << "\n";
}

} // namespace rfid_044_nc

int main() {
    using namespace rfid_044_nc;
    std::uint32_t rfid_tags[50] = {0};
    store_tag_id(rfid_tags);
    return 0;
}
