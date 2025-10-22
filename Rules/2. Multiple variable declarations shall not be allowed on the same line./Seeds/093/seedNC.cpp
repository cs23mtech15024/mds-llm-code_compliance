// Context: Solar tracker dual-axis controller

#include <iostream>
int main(){
    float az=0.0F, el=0.0F;        // NC
    float k=0.2F, bias=0.0F;       // NC
    unsigned steps=0U, faults=0U;  // NC
    az += 0.5F; el += 0.3F; steps++;
    std::cout<<az<<","<<el<<","<<k<<","<<bias<<","<<steps<<","<<faults<<"\n";
    return 0;
}
