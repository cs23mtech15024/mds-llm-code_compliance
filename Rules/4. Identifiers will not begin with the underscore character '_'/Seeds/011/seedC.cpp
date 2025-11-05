// Context: Battery voltage monitor

// Seed 011 — C: variables without underscore prefix
#include <iostream>
int main(){
    float voltage = 3.7F; // C
    float current = 0.5F; // C
    float power = voltage * current;
    std::cout << "power=" << power << "\n";
    return 0;
}