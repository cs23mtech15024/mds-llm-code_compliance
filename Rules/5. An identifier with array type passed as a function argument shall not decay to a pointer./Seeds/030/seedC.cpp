// Context: Humidity sensor moving average

// Seed 030 — C: humidity samples by reference
#include <iostream>
float smooth_humidity(float (&readings)[10]) { // C
    return (readings[0] + readings[1]) / 2.0F;
}
int main(){
    float humidity_buffer[10] = {65.5F, 66.0F};
    std::cout << "humidity=" << smooth_humidity(humidity_buffer) << "\n";
    return 0;
}