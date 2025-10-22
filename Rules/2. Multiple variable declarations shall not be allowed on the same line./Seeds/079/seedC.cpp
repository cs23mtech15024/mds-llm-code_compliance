// Context: Electric scooter fleet charger balancer

#include <iostream>
int main(){
    unsigned plugs=12U;    // C
    unsigned bays=6U;      // C
    float load=0.0F;       // C
    float bias=0.0F;       // C
    int moves=0;           // C
    int faults=0;          // C
    load += 0.3F; bias += 0.05F;
    std::cout<<plugs<<","<<bays<<","<<load<<","<<bias<<","<<moves<<","<<faults<<"\n";
    return 0;
}
