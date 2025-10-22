// Context: Offshore wind turbine yaw alignment supervisor

#include <iostream>
int main(){
    float yaw=0.0F, err=0.0F;        // NC
    float rate=0.0F, gain=0.3F;      // NC
    unsigned moves=0U, faults=0U;    // NC
    err = -0.4F; rate += gain*err;
    std::cout<<yaw<<","<<err<<","<<rate<<","<<gain<<","<<moves<<","<<faults<<"\n";
    return 0;
}
