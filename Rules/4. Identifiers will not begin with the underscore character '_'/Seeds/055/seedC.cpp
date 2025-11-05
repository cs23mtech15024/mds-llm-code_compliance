// Context: Damping coefficient setter

// Seed 055 — C: function and parameter without underscore prefix
#include <iostream>
void set_damping(float coef) { // C
    std::cout << "damping=" << coef << "\n";
}
int main(){
    set_damping(0.7F);
    return 0;
}