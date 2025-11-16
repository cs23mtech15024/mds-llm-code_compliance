// Context: Accelerometer calibration data

// Seed 011 — NC: calibration array decays to pointer
#include <iostream>
void apply_calibration(float offsets[]) { // NC
    offsets[0] += 0.05F;
    std::cout << "offset_x=" << offsets[0] << "\n";
}
int main(){
    float accel_offsets[3] = {0.0F, 0.0F, 0.0F};
    apply_calibration(accel_offsets);
    return 0;
}