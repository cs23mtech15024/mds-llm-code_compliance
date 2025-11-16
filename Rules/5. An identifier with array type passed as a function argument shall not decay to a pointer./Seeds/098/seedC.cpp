// Context: Clutch engagement pressure curve

// Seed 098 — C: pressure curve by reference
#include <iostream>
void apply_clutch_curve(float (&pressures)[20]) { // C
    pressures[0] = 25.0F;
    std::cout << "pressure0=" << pressures[0] << "\n";
}
int main(){
    float clutch_curve[20] = {0};
    apply_clutch_curve(clutch_curve);
    return 0;
}