// Context: 5G beamforming antenna array phase controller

#include <iostream>
int main(){
    float phase=0.0F, amp=1.0F;       // NC
    double freq=28.0, bw=100.0;       // NC
    unsigned beams=4U, faults=0U;     // NC
    phase += 0.5F; amp -= 0.1F; beams++;
    std::cout<<phase<<","<<amp<<","<<freq<<","<<bw<<","<<beams<<","<<faults<<"\n";
    return 0;
}
