// Context: Conveyor belt speed sensors

// Seed 096 — C: belt speeds by reference
#include <iostream>
void synchronize_belts(float (&speeds)[12]) { // C
    speeds[0] = 1.5F;
    std::cout << "belt0=" << speeds[0] << "m/s\n";
}
int main(){
    float belt_speeds[12] = {0};
    synchronize_belts(belt_speeds);
    return 0;
}