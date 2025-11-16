// Context: Elevator floor position buffer

// ------ Non-Compliant Program (050_nc.cpp)
// Context: Store last visited floor in slot 0 and echo a check
// Rule: Array parameter decays to pointer (VIOLATION)
#include <iostream>
#include <iomanip>
#include <cstddef>

namespace lift_050_nc {

// NC helper: pointer + length for write
static void write_floor(int *pos, std::size_t n, int f) {
    if (n > 0U) pos[0] = (f < 0) ? 0 : f;
}

void record_floor(int positions[]) { // NC API
    write_floor(positions, 100U, 5);
    std::cout << "floor=" << positions[0] << ", isGround=" << std::boolalpha << (positions[0] == 0) << "\n";
}

} // namespace lift_050_nc

int main() {
    using namespace lift_050_nc;
    int elevator_floors[100] = {0};
    record_floor(elevator_floors);
    return 0;
}
