// Context: Collision detection boundary boxes

// ------ Non-Compliant Program (058_nc.cpp)
// Context: Axis-aligned bounding boxes (AABB) collision check
// Rule: Array decays to pointer (VIOLATED)
// NC: check_collision uses pointer for boxes data
#include <iostream>
#include <iomanip>

namespace collide_058_nc {

bool check_collision(float boxes[]) { // NC API
    // box format: [x1,y1,x2,y2, ...]
    return boxes[0] < boxes[2] && boxes[1] < boxes[3];
}

} // namespace collide_058_nc

int main() {
    using namespace collide_058_nc;
    float bbox[8] = {0.0F, 0.0F, 10.0F, 10.0F, 0,0,0,0};
    std::cout << std::boolalpha
              << "collision=" << check_collision(bbox) << "\n";
    return 0;
}
