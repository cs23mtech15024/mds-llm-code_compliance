// Context: Electric ferry docking thruster coordinator

// ------ Compliant Program (061_c.cpp)
// Fix: single-declarator declarations (8-0-1 compliant).
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
namespace dock_061 {
    struct Thr { float fx; float fy; float yaw; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void coordinate(){
        float fx=0.0F;                            // C
        float fy=0.0F;                            // C
        float yaw=0.0F;                           // C
        float gain=0.8F;                          // C
        unsigned steps=0U;                        // C
        unsigned faults=0U;                       // C
        Thr t{0.0F,0.0F,0.0F};
        std::vector<float> refs{0.4F,-0.2F,0.3F,-0.1F,0.0F};
        for (std::size_t i=0;i<refs.size();++i){
            float ex = refs[i] - t.fx;
            float ey = -t.fy;
            fx = clampf(fx + gain*ex, -1.0F, 1.0F);
            fy = clampf(fy + gain*ey, -1.0F, 1.0F);
            yaw = clampf(yaw + 0.2F*(ex - ey), -0.8F, 0.8F);
            t.fx = fx; t.fy = fy; t.yaw = yaw; steps++;
            if (std::fabs(ex)+std::fabs(ey)>1.2F){ faults++; }
            if ((i%2U)==0U){
                std::cout<<"i="<<i<<" fx="<<t.fx<<" fy="<<t.fy<<" yaw="<<t.yaw<<"\n";
            }
        }
        std::cout<<"steps="<<steps<<" faults="<<faults<<"\n";
    }
}
int main(){ dock_061::coordinate(); return 0; }