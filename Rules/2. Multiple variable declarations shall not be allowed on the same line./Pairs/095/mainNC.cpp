// Context: Hydroelectric turbine blade pitch optimizer

// ------ Non-Compliant Program (095_nc.cpp)
// Multiple declarators per declaration (// NC) — violates MISRA C++ 8-0-1.
#include <iostream>
#include <vector>
#include <cmath>
namespace hydro_095 {
    struct Turb { float pitch; float rpm; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void optimize(){
        float pitch=0.5F, rpm=300.0F;           // NC
        float step=0.0F, eff=0.0F;              // NC
        unsigned t=0U, alarms=0U;               // NC
        std::vector<float> load{0.3F,0.6F,0.1F,-0.2F,0.4F};
        for (std::size_t i=0;i<load.size();++i){
            step = 0.02F + 0.01F*load[i];
            pitch = clampf(pitch + step, 0.2F, 0.9F);
            rpm = clampf(rpm + 2.0F + 5.0F*load[i], 250.0F, 360.0F);
            eff = clampf(0.8F + 0.1F*load[i] - std::fabs(0.65F-pitch), 0.5F, 0.95F);
            if (eff<0.6F){ alarms++; }
            t++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" pitch="<<pitch<<" rpm="<<rpm<<" eff="<<eff<<"\n"; }
        }
        std::cout<<"t="<<t<<" alarms="<<alarms<<"\n";
    }
}
int main(){ hydro_095::optimize(); return 0; }
