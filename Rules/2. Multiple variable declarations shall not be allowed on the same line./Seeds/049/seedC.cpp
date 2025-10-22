// Context: Data center chilled-water valve optimizer

#include <iostream>
int main(){
    float supply=7.0F;      // C
    float returnT=12.0F;    // C
    float gain=1.0F;        // C
    float bias=0.0F;        // C
    unsigned loops=0U;      // C
    unsigned faults=0U;     // C
    returnT += 0.3F; bias += 0.05F;
    std::cout<<supply<<","<<returnT<<","<<gain<<","<<bias<<","<<loops<<","<<faults<<"\n";
    return 0;
}
