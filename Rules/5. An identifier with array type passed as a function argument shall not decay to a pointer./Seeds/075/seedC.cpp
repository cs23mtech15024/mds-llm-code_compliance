// Context: Particle filter weight array

// Seed 075 — C: particle weights by reference
#include <iostream>
void resample_particles(float (&weights)[500]) { // C
    weights[0] = weights[0] / 100.0F;
    std::cout << "weight0=" << weights[0] << "\n";
}
int main(){
    float particle_weights[500] = {1.0F};
    resample_particles(particle_weights);
    return 0;
}