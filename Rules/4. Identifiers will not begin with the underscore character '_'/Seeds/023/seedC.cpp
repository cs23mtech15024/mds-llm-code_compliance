// Context: Velocity limit checker

// Seed 023 — C: function without underscore prefix
#include <iostream>
bool check_velocity_limit(float vel, float limit) { // C
    return vel <= limit;
}
int main(){
    std::cout << "ok=" << check_velocity_limit(45.0F, 50.0F) << "\n";
    return 0;
}