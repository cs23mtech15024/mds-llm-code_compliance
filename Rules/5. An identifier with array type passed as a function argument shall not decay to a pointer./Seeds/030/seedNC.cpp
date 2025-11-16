// Context: Humidity sensor moving average

// Seed 030 — NC: humidity samples decay to pointer
#include <iostream>
float smooth_humidity(float readings[]) { // NC
    return (readings[0] + readings[1]) / 2.0F;
}
int main(){
    float humidity_buffer[10] = {65.5F, 66.0F};
    std::cout << "humidity=" << smooth_humidity(humidity_buffer) << "\n";
    return 0;
}