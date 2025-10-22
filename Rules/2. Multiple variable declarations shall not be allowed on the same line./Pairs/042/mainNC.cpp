// Context: Space telescope reaction wheel balancer

// ------ Non-Compliant Program (042_nc.cpp)
// 8-0-1 violations via multiple declarators per declaration (// NC).
#include <iostream>
#include <vector>
#include <cmath>
#include <cstddef>
namespace rw_042 {
    struct Wheel { float wx; float wy; }; // OK
    static float clip(float v,float m){ return std::max(-m,std::min(m,v)); }
    void balance(){
        float wx=0.0F, wy=0.0F;                // NC
        double bias=0.0, set=0.02;             // NC
        int alarms=0, resets=0;                // NC
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
