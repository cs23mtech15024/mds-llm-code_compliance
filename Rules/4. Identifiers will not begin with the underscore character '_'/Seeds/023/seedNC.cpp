// Context: Velocity limit checker

// Seed 023 — NC: function starts with underscore
#include <iostream>
bool _check_velocity_limit(float vel, float limit) { // NC
    return vel <= limit;
}
int main(){
    std::cout << "ok=" << _check_velocity_limit(45.0F, 50.0F) << "\n";
    return 0;
}