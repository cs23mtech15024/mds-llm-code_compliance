// Context: Solar tracker dual-axis controller

// ------ Non-Compliant Program (093_nc.cpp)
// Demonstrates 8-0-1 violations using grouped declarators.
#include <iostream>
#include <vector>
#include <cmath>
namespace tracker_093 {
    struct Pose { float az; float el; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void control(){
        float az=0.0F, el=0.0F;                 // NC
        float k=0.2F, bias=0.0F;                // NC
        unsigned steps=0U, faults=0U;           // NC
        std::vector<float> sun{0.6F,0.2F,-0.1F,0.4F,-0.2F};
        for (std::size_t i=0;i<sun.size();++i){
            az = clampf(az + k*sun[i] + bias, -3.14F, 3.14F);
            el = clampf(el + 0.8F*k*sun[i], -1.3F, 1.3F);
            steps++; if (std::fabs(sun[i])>0.5F){ faults++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" az="<<az<<" el="<<el<<"\n"; }
        }
        std::cout<<"steps="<<steps<<" faults="<<faults<<"\n";
    }
}
int main(){ tracker_093::control(); return 0; }
