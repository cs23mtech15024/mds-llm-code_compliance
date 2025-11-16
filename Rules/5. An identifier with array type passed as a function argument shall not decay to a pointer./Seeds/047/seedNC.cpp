// Context: Load cell weight samples

// Seed 047 — NC: weight samples decay to pointer
#include <iostream>
float calculate_weight(float samples[]) { // NC
    return samples[0] * 0.001F;
}
int main(){
    float loadcell_samples[32] = {5000.0F};
    std::cout << "weight_kg=" << calculate_weight(loadcell_samples) << "\n";
    return 0;
}