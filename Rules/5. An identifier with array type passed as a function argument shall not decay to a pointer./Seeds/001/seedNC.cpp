// Context: Temperature sensor array processor

// Seed 001 — NC: array decays to pointer
#include <iostream>
void process_temperatures(int temps[]) { // NC
    std::cout << "temp0=" << temps[0] << "\n";
}
int main(){
    int sensor_data[5] = {20, 21, 22, 23, 24};
    process_temperatures(sensor_data);
    return 0;
}