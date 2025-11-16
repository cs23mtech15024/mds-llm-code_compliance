// Context: Particle filter weight array

// Seed 075 — NC: particle weights decay to pointer
#include <iostream>
void resample_particles(float weights[]) { // NC
    weights[0] = weights[0] / 100.0F;
    std::cout << "weight0=" << weights[0] << "\n";
}
int main(){
    float particle_weights[500] = {1.0F};
    resample_particles(particle_weights);
    return 0;
}