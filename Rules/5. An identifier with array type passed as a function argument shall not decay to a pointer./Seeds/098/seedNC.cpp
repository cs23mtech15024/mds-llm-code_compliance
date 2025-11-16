// Context: Clutch engagement pressure curve

// Seed 098 — NC: pressure curve decays to pointer
#include <iostream>
void apply_clutch_curve(float pressures[]) { // NC
    pressures[0] = 25.0F;
    std::cout << "pressure0=" << pressures[0] << "\n";
}
int main(){
    float clutch_curve[20] = {0};
    apply_clutch_curve(clutch_curve);
    return 0;
}