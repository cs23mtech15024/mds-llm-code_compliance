// Context: Motor control speed helper function

// Seed 005 — NC: helper function starts with underscore
#include <iostream>
float _calculate_rpm(float freq) { // NC
    return freq * 60.0F;
}
int main(){
    std::cout << "rpm=" << _calculate_rpm(50.0F) << "\n";
    return 0;
}