// Context: Offshore wind turbine yaw alignment supervisor

#include <iostream>
int main(){
    float yaw=0.0F;       // C
    float err=0.0F;       // C
    float rate=0.0F;      // C
    float gain=0.3F;      // C
    unsigned moves=0U;    // C
    unsigned faults=0U;   // C
    err = -0.4F; rate += gain*err;
    std::cout<<yaw<<","<<err<<","<<rate<<","<<gain<<","<<moves<<","<<faults<<"\n";
    return 0;
}
