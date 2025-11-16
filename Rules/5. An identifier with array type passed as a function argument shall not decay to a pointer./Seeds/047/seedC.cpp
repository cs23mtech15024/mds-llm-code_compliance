// Context: Load cell weight samples

// Seed 047 — C: weight samples by reference
#include <iostream>
float calculate_weight(float (&samples)[32]) { // C
    return samples[0] * 0.001F;
}
int main(){
    float loadcell_samples[32] = {5000.0F};
    std::cout << "weight_kg=" << calculate_weight(loadcell_samples) << "\n";
    return 0;
}