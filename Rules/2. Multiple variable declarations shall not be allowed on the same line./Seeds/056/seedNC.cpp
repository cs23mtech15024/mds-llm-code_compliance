// Context: Precision agriculture variable-rate sprayer

#include <iostream>
int main(){
    float speed=2.5F, width=12.0F;  // NC
    float rate=0.0F, bias=0.0F;     // NC
    unsigned zones=8U, faults=0U;   // NC
    rate = 0.3F; zones += 2U;
    std::cout<<speed<<","<<width<<","<<rate<<","<<bias<<","<<zones<<","<<faults<<"\n";
    return 0;
}
