// Context: Urban traffic light adaptive timing

#include <iostream>
int main(){
    unsigned nS=20U;       // C
    unsigned nE=15U;       // C
    float bias=0.0F;       // C
    float gain=1.0F;       // C
    int faults=0;          // C
    int rescales=0;        // C
    bias += 0.1F; gain += 0.05F;
    std::cout<<nS<<","<<nE<<","<<bias<<","<<gain<<","<<faults<<","<<rescales<<"\n";
    return 0;
}
