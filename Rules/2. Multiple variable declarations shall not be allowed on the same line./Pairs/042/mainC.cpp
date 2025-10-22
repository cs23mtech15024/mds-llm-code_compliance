// Context: Space telescope reaction wheel balancer

// ------ Compliant Program (042_c.cpp)
// Compliant: one declarator per declaration.
#include <iostream>
#include <vector>
#include <cmath>
#include <cstddef>
namespace rw_042 {
    struct Wheel { float wx; float wy; }; // OK
    static float clip(float v,float m){ return std::max(-m,std::min(m,v)); }
    void balance(){
        float wx=0.0F;                           // C
        float wy=0.0F;                           // C
        double bias=0.0;                         // C
        double set=0.02;                         // C
        int alarms=0;                            // C
        int resets=0;                            // C
        Wheel w{wx,wy};
        std::vector<float> errs;
        for (std::size_t k=0;k<14U;++k){
            float e = static_cast<float>(set) - w.wx;
            float u = clip(e*0.5F + static_cast<float>(bias), 0.02F);
            w.wx += u; w.wy -= u*0.3F; errs.push_back(e);
            if (std::fabs(e)>0.05F){ alarms++; }
            if ((k%5U)==0U){ resets++; }
            if ((k%2U)==0U){ std::cout<<"k="<<k<<" wx="<<w.wx<<" wy="<<w.wy<<" e="<<e<<"\n"; }
        }
        std::cout<<"alarms="<<alarms<<" resets="<<resets<<"\n";
    }
}
int main(){ rw_042::balance(); return 0; }
