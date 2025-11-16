// Context: CAN bus message identifier table

// Seed 012 — C: message ID array by reference
#include <iostream>
#include <cstdint>
bool is_valid_id(std::uint32_t (&ids)[16]) { // C
    return ids[0] < 0x800;
}
int main(){
    std::uint32_t can_ids[16] = {0x123};
    std::cout << "valid=" << is_valid_id(can_ids) << "\n";
    return 0;
}