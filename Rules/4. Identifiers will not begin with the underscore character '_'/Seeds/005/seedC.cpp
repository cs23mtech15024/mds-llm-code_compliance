// Context: Motor control speed helper function

// Seed 005 — C: helper function without underscore prefix
#include <iostream>
float calculate_rpm(float freq) { // C
    return freq * 60.0F;
}
int main(){
    std::cout << "rpm=" << calculate_rpm(50.0F) << "\n";
    return 0;
}