// Context: High-speed rail pantograph contact monitor

#include <iostream>
int main(){
    float force=85.0F;    // C
    float vib=0.0F;       // C
    unsigned hits=0U;     // C
    unsigned faults=0U;   // C
    bool ice=false;       // C
    bool arc=false;       // C
    vib += 0.2F; hits+=1U;
    std::cout<<force<<","<<vib<<","<<hits<<","<<faults<<","<<ice<<","<<arc<<"\n";
    return 0;
}
