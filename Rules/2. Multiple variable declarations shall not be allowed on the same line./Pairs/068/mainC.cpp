// Context: Offshore wind turbine yaw alignment supervisor

// ------ Compliant Program (068_c.cpp)
// Compliant: one declarator per declaration across the file.
#include <iostream>
#include <vector>
#include <cmath>
namespace yaw_068 {
    struct Yaw { float yaw; float rate; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void align(){
        float yaw=0.0F;                           // C
        float err=0.0F;                           // C
        float rate=0.0F;                          // C
        float gain=0.3F;                          // C
        unsigned moves=0U;                        // C
        unsigned faults=0U;                       // C
        std::vector<float> wind{-0.4F,-0.3F,0.2F,0.5F,-0.1F};
        for (std::size_t i=0;i<wind.size();++i){
            err = wind[i]; rate = clampf(rate + gain*err, -0.6F, 0.6F);
            yaw = clampf(yaw + rate, -3.14F, 3.14F); moves++;
            if (std::fabs(err)>0.45F){ faults++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" yaw="<<yaw<<" rate="<<rate<<" err="<<err<<"\n"; }
        }
        std::cout<<"moves="<<moves<<" faults="<<faults<<"\n";
    }
}
int main(){ yaw_068::align(); return 0; }
