// Context: Occupancy grid map cells

// ------ Non-Compliant Program (089_nc.cpp)
// Context: Occupancy grid map cells (10000 entries)
// Rule: Array parameter decays to pointer (VIOLATION)
// Risk: Function unaware of full grid size
#include <iostream>
#include <cstdint>
#include <cstddef>

namespace grid_089_nc {

static void mark_occupied(std::uint8_t *c, std::size_t n){ if(n>0U){ c[0] = 255; } }

void update_grid(std::uint8_t cells[]) { // NC API
    const std::size_t N = 10000U; (void)N;
    mark_occupied(cells, 10000U);
    std::cout << "cell0=" << static_cast<int>(cells[0]) << "\n";
}

} // namespace grid_089_nc

int main(){
    using namespace grid_089_nc;
    std::uint8_t map[10000] = {0};
    update_grid(map);
    return 0;
}
