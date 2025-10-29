// Context: Mining haul truck tire pressure monitor

#include <iostream>
int main(){
    float pFL=95.0F, pFR=96.0F;      // NC
    float pRL=100.0F, pRR=99.0F;     // NC
    unsigned faults=0U, warns=0U;    // NC
    pFR -= 1.0F; pRR -= 2.0F;
    std::cout<<pFL<<","<<pFR<<","<<pRL<<","<<pRR<<","<<faults<<","<<warns<<"\n";
    return 0;
}
