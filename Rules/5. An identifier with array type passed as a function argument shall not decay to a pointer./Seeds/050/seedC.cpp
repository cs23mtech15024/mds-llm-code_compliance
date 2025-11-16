// Context: Elevator floor position buffer

// Seed 050 — C: floor positions by reference
#include <iostream>
void record_floor(int (&positions)[100]) { // C
    positions[0] = 5;
    std::cout << "floor=" << positions[0] << "\n";
}
int main(){
    int elevator_floors[100] = {0};
    record_floor(elevator_floors);
    return 0;
}