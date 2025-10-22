// Context: Warehouse picking robot joint limit supervisor

// ------ Non-Compliant Program (067_nc.cpp)
// Groups declarators (// NC), violating 8-0-1.
#include <iostream>
#include <array>
#include <algorithm>
namespace joints_067 {
    struct Joint { float q; float v; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void supervise(){
        float q1=0.0F, q2=0.0F;                 // NC
        float v1=0.0F, v2=0.0F;                 // NC
        unsigned trips=0U, warns=0U;            // NC
        std::array<float,8U> cmd{0.5F,0.4F,-0.3F,0.2F,0.6F,-0.7F,0.1F,0.0F};
        for (std::size_t i=0;i<cmd.size();++i){
            v1 = clampf(v1 + 0.1F*cmd[i], -1.0F, 1.0F);
            v2 = clampf(v2 + 0.2F*cmd[i], -1.0F, 1.0F);
            q1 = clampf(q1 + v1, -1.5F, 1.5F);
            q2 = clampf(q2 + v2, -1.5F, 1.5F);
            if (std::fabs(q1)>1.4F || std::fabs(q2)>1.4F){ trips++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" q1="<<q1<<" q2="<<q2<<"\n"; }
        }
        std::cout<<"trips="<<trips<<" warns="<<warns<<"\n";
    }
}
int main(){ joints_067::supervise(); return 0; }
