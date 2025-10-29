// Context: 5G beamforming antenna array phase controller

#include <iostream>
int main(){
    float phase=0.0F;     // C
    float amp=1.0F;       // C
    double freq=28.0;     // C
    double bw=100.0;      // C
    unsigned beams=4U;    // C
    unsigned faults=0U;   // C
    phase += 0.5F; amp -= 0.1F; beams++;
    std::cout<<phase<<","<<amp<<","<<freq<<","<<bw<<","<<beams<<","<<faults<<"\n";
    return 0;
}
