// Context: Urban traffic light adaptive timing

#include <iostream>
int main(){
    unsigned nS=20U, nE=15U;         // NC
    float bias=0.0F, gain=1.0F;      // NC
    int faults=0, rescales=0;        // NC
    bias += 0.1F; gain += 0.05F;
    std::cout<<nS<<","<<nE<<","<<bias<<","<<gain<<","<<faults<<","<<rescales<<"\n";
    return 0;
}
