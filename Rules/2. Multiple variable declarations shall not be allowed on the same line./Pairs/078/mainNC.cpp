// Context: Mountain tunnel ventilation controller

// ------ Non-Compliant Program (078_nc.cpp)
// Groups declarators; violates MISRA C++ 8-0-1.
#include <iostream>
#include <array>
#include <algorithm>
namespace tunnel_078 {
    struct Air { float co; float nox; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void control(){
        float co=3.0F, nox=0.5F;                // NC
        float fan=0.0F, damper=0.0F;            // NC
        unsigned t=0U, alarms=0U;               // NC
        std::array<float,8U> meas{3.1F,3.4F,2.9F,4.2F,5.0F,2.5F,2.0F,3.0F};
        for (std::size_t i=0;i<meas.size();++i){
            co = meas[i]; nox = clampf(nox + 0.05F*(i%2U?1.0F:-1.0F), 0.2F, 1.2F);
            fan = clampf(fan + (co-3.0F)*0.3F, 0.0F, 1.0F);
            damper = clampf(damper + (nox-0.6F)*0.2F, 0.0F, 1.0F);
            if (co>4.5F){ alarms++; }
            t++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" co="<<co<<" fan="<<fan<<" d="<<damper<<"\n"; }
        }
        std::cout<<"t="<<t<<" alarms="<<alarms<<"\n";
    }
}
int main(){ tunnel_078::control(); return 0; }
