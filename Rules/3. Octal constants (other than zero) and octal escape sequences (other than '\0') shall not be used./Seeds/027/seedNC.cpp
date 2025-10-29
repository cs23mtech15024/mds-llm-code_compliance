// Context: Bitmask parser for device flags

#include <iostream>
#include <cstdint>
int main(){
    uint8_t v = 0b10110101u;
    uint8_t low3 = v & 07u; // NC: octal constant 07 = 7 decimal
    std::cout<<"low3="<<static_cast<int>(low3)<<"\n";
    return 0;
}
