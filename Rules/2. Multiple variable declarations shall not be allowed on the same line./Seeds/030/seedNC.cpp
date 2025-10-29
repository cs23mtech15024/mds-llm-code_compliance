// Context: High-speed rail pantograph contact monitor

#include <iostream>
int main(){
    float force=85.0F, vib=0.0F;     // NC
    unsigned hits=0U, faults=0U;     // NC
    bool ice=false, arc=false;       // NC
    vib += 0.2F; hits+=1U;
    std::cout<<force<<","<<vib<<","<<hits<<","<<faults<<","<<ice<<","<<arc<<"\n";
    return 0;
}
