// Context: Motor driver header with speed variable

// -------- Non-Compliant Program (prog_024_nc.cpp)
// Context: Motor driver control
#include <iostream>
#include "seedNC.h" // seed024_motor_speed, seed024_set_speed()

namespace motor_nc {

void accelerate(int inc) {
    seed024_motor_speed += inc;
}

void run(int speeds[], std::size_t n) { // NC
    for (std::size_t i = 0; i < n; ++i) {
        seed024_set_speed(speeds[i]);
        accelerate(10);
        std::cout << "speed=" << seed024_motor_speed << "\n";
    }
}

int sum(int arr[], std::size_t n) {
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) s += arr[i];
    return s;
}

} // namespace motor_nc

int main() {
    using namespace motor_nc;
    int sp[4] = {1000,1200,1400,1600};
    run(sp,4);
    std::cout << "sum=" << sum(sp,4) << "\n";
    return 0;
}
