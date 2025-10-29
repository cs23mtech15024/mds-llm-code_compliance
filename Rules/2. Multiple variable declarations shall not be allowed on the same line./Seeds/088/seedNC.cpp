// Context: Tokamak plasma diagnostic system

#include <iostream>
int main(){
    double temperature=15000000.0, density=0.0; // NC
    float confinement=0.0F, beta=0.0F;    // NC
    unsigned pulses=0U, disruptions=0U;   // NC
    temperature += 1000.0; pulses++;
    std::cout<<temperature<<","<<density<<","<<confinement<<","<<beta<<","<<pulses<<","<<disruptions<<"\n";
    return 0;
}
