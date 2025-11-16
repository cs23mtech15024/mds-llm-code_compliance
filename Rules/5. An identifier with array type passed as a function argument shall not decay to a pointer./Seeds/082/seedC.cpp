// Context: Satellite orbital elements

// Seed 082 — C: orbital elements by reference
#include <iostream>
void update_orbit(double (&elements)[6]) { // C
    elements[0] = 7000.0;
    std::cout << "semi_major=" << elements[0] << "\n";
}
int main(){
    double orbital_params[6] = {0};
    update_orbit(orbital_params);
    return 0;
}