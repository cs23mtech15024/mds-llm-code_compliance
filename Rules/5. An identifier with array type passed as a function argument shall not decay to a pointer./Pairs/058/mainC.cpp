// Context: Collision detection boundary boxes

// ------ Compliant Program (058_c.cpp)
// Context: Axis-aligned bounding boxes (AABB) collision check
// Rule: Preserve array extent (COMPLIANT)
// C: check_collision takes reference to array[8]
#include <iostream>
#include <iomanip>

namespace collide_058_c {

bool check_collision(float (&boxes)[8]) { // C API exact bound
    return boxes[0] < boxes[2] && boxes[1] < boxes[3];
}

} // namespace collide_058_c

int main() {
    using namespace collide_058_c;
    float bbox[8] = {0.0F, 0.0F, 10.0F, 10.0F, 0,0,0,0};
    std::cout << std::boolalpha
              << "collision=" << check_collision(bbox) << "\n";
    return 0;
}
