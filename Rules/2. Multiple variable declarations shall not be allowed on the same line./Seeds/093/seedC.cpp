// Context: Solar tracker dual-axis controller

#include <iostream>
int main(){
    float az=0.0F;        // C
    float el=0.0F;        // C
    float k=0.2F;         // C
    float bias=0.0F;      // C
    unsigned steps=0U;    // C
    unsigned faults=0U;   // C
    az += 0.5F; el += 0.3F; steps++;
    std::cout<<az<<","<<el<<","<<k<<","<<bias<<","<<steps<<","<<faults<<"\n";
    return 0;
}
