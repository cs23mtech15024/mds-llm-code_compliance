// Context: EMV TLV field permission mask

// Seed 033 — C: uppercase hex in permission mask
#include <iostream>
int main(){
    unsigned perm=0x7FF; // C
    std::cout << "emv_perm=0x" << std::hex << perm << "\n";
    return 0;
}