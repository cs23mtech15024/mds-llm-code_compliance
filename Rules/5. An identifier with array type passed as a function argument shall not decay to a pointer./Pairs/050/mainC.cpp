// Context: Elevator floor position buffer

// ------ Compliant Program (050_c.cpp)
// Context: Store last visited floor in slot 0 and echo a check
// Status: Array passed by reference (COMPLIANT)
#include <iostream>
#include <iomanip>

namespace lift_050_c {

static void write_floor(int (&pos)[100], int f) {
    pos[0] = (f < 0) ? 0 : f;
}

void record_floor(int (&positions)[100]) { // C API
    write_floor(positions, 5);
    std::cout << "floor=" << positions[0] << ", isGround=" << std::boolalpha << (positions[0] == 0) << "\n";
}

} // namespace lift_050_c

int main() {
    using namespace lift_050_c;
    int elevator_floors[100] = {0};
    record_floor(elevator_floors);
    return 0;
}
