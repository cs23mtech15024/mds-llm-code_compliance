// Context: Battery voltage monitor

// Seed 011 — NC: multiple variables start with underscore
#include <iostream>
int main(){
    float _voltage = 3.7F; // NC
    float _current = 0.5F; // NC
    float power = _voltage * _current;
    std::cout << "power=" << power << "\n";
    return 0;
}