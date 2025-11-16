// Context: Gyroscope angular rate buffer

// Seed 023 — NC: gyro rate array decays to pointer
#include <iostream>
void process_gyro_data(float rates[]) { // NC
    rates[0] *= 0.0175F;
    std::cout << "rate_x=" << rates[0] << "\n";
}
int main(){
    float gyro_rates[3] = {10.5F, 12.0F, 8.5F};
    process_gyro_data(gyro_rates);
    return 0;
}