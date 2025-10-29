// Context: Solar tracker dual-axis alignment

#include <iostream>
int main(){
    float az=0.0F;         // C
    float el=0.0F;         // C
    float azRate=0.0F;     // C
    float elRate=0.0F;     // C
    unsigned faults=0U;    // C
    unsigned moves=0U;     // C
    az+=0.2F; el+=0.1F; moves++;
    std::cout<<az<<","<<el<<","<<azRate<<","<<elRate<<","<<faults<<","<<moves<<"\n";
    return 0;
}
