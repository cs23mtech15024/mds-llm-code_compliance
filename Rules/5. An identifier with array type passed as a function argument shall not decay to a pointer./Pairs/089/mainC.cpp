// Context: Occupancy grid map cells

// ------ Compliant Program (089_c.cpp)
// Context: Occupancy grid map cells (10000 entries)
// Status: Array passed by reference (COMPLIANT)
// Benefit: Type safety on map size
#include <iostream>
#include <cstdint>

namespace grid_089_c {

static void mark_occupied(std::uint8_t (&c)[10000]){ c[0] = 255; }

void update_grid(std::uint8_t (&cells)[10000]) { // C API
    mark_occupied(cells);
    std::cout << "cell0=" << static_cast<int>(cells[0]) << "\n";
}

} // namespace grid_089_c

int main(){
    using namespace grid_089_c;
    std::uint8_t map[10000] = {0};
    update_grid(map);
    return 0;
}
