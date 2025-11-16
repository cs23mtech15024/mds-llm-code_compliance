// Context: Occupancy grid map cells

// Seed 089 — NC: grid cells decay to pointer
#include <iostream>
#include <cstdint>
void update_occupancy_grid(std::uint8_t cells[]) { // NC
    cells[0] = 255;
    std::cout << "cell0=" << static_cast<int>(cells[0]) << "\n";
}
int main(){
    std::uint8_t grid_map[10000] = {0};
    update_occupancy_grid(grid_map);
    return 0;
}