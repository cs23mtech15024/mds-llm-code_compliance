// Context: Elevator floor position buffer

// Seed 050 — NC: floor positions decay to pointer
#include <iostream>
void record_floor(int positions[]) { // NC
    positions[0] = 5;
    std::cout << "floor=" << positions[0] << "\n";
}
int main(){
    int elevator_floors[100] = {0};
    record_floor(elevator_floors);
    return 0;
}