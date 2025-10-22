// Context: Data center chilled-water valve optimizer

#include <iostream>
int main(){
    float supply=7.0F, returnT=12.0F; // NC
    float gain=1.0F, bias=0.0F;       // NC
    unsigned loops=0U, faults=0U;     // NC
    returnT += 0.3F; bias += 0.05F;
    std::cout<<supply<<","<<returnT<<","<<gain<<","<<bias<<","<<loops<<","<<faults<<"\n";
    return 0;
}
