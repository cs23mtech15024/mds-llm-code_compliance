// Context: Precision agriculture variable-rate sprayer

#include <iostream>
int main(){
    float speed=2.5F;     // C
    float width=12.0F;    // C
    float rate=0.0F;      // C
    float bias=0.0F;      // C
    unsigned zones=8U;    // C
    unsigned faults=0U;   // C
    rate = 0.3F; zones += 2U;
    std::cout<<speed<<","<<width<<","<<rate<<","<<bias<<","<<zones<<","<<faults<<"\n";
    return 0;
}
