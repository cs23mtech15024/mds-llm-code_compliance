// Context: Damping coefficient setter

// Seed 055 — NC: function and parameter start with underscore
#include <iostream>
void _set_damping(float _coef) { // NC
    std::cout << "damping=" << _coef << "\n";
}
int main(){
    _set_damping(0.7F);
    return 0;
}