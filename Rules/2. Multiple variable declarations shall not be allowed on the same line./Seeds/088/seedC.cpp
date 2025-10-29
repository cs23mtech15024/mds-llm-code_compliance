// Context: Tokamak plasma diagnostic system

#include <iostream>
int main(){
    double temperature=15000000.0; // C
    double density=0.0;            // C
    float confinement=0.0F;        // C
    float beta=0.0F;               // C
    unsigned pulses=0U;            // C
    unsigned disruptions=0U;       // C
    temperature += 1000.0; pulses++;
    std::cout<<temperature<<","<<density<<","<<confinement<<","<<beta<<","<<pulses<<","<<disruptions<<"\n";
    return 0;
}
