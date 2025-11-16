// Context: Collision detection boundary boxes

// Seed 058 — C: bounding boxes by reference
#include <iostream>
bool check_collision(float (&boxes)[8]) { // C
    return boxes[0] < boxes[2];
}
int main(){
    float bbox[8] = {0.0F, 0.0F, 10.0F, 10.0F};
    std::cout << "collision=" << check_collision(bbox) << "\n";
    return 0;
}