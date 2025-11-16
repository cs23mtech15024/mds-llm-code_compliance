// Context: Encoder ring segment markers

// Seed 083 — C: segment markers by reference
#include <iostream>
#include <cstdint>
void calibrate_encoder(std::uint16_t (&markers)[360]) { // C
    markers[0] = 1024;
    std::cout << "marker0=" << markers[0] << "\n";
}
int main(){
    std::uint16_t encoder_marks[360] = {0};
    calibrate_encoder(encoder_marks);
    return 0;
}