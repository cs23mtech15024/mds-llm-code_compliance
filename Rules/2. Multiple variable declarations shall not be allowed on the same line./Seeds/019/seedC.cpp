// Context: Mining haul truck tire pressure monitor

#include <iostream>
int main(){
    float pFL=95.0F;       // C
    float pFR=96.0F;       // C
    float pRL=100.0F;      // C
    float pRR=99.0F;       // C
    unsigned faults=0U;    // C
    unsigned warns=0U;     // C
    pFR -= 1.0F; pRR -= 2.0F;
    std::cout<<pFL<<","<<pFR<<","<<pRL<<","<<pRR<<","<<faults<<","<<warns<<"\n";
    return 0;
}
