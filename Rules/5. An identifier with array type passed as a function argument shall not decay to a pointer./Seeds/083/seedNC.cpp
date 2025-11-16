// Context: Encoder ring segment markers

// Seed 083 — NC: segment markers decay to pointer
#include <iostream>
#include <cstdint>
void calibrate_encoder(std::uint16_t markers[]) { // NC
    markers[0] = 1024;
    std::cout << "marker0=" << markers[0] << "\n";
}
int main(){
    std::uint16_t encoder_marks[360] = {0};
    calibrate_encoder(encoder_marks);
    return 0;
}