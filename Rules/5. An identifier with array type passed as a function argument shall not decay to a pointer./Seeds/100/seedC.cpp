// Context: Brake pad wear indicator values

// Seed 100 — C: wear values by reference
#include <iostream>
bool check_brake_wear(float (&wear_levels)[4]) { // C
    return wear_levels[0] < 2.0F;
}
int main(){
    float pad_wear[4] = {1.5F, 2.5F, 1.8F, 2.2F};
    std::cout << "needs_replacement=" << check_brake_wear(pad_wear) << "\n";
    return 0;
}