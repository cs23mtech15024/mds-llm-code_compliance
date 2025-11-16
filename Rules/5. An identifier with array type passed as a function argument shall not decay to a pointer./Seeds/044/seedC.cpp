// Context: RFID tag identifier storage

// Seed 044 — C: RFID tag array by reference
#include <iostream>
#include <cstdint>
void store_tag_id(std::uint32_t (&tag_ids)[50]) { // C
    tag_ids[0] = 0x12345678;
    std::cout << "tag0=0x" << std::hex << tag_ids[0] << "\n";
}
int main(){
    std::uint32_t rfid_tags[50] = {0};
    store_tag_id(rfid_tags);
    return 0;
}