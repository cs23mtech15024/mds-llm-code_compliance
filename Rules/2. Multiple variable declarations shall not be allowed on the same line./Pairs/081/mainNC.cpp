// Context: Autonomous harbor oil spill skimmer route planner

// ------ Non-Compliant Program (081_nc.cpp)
// Rule: MISRA C++ 8-0-1 — a declaration shall contain no more than one declarator.
// This file purposely groups declarators (// NC) to illustrate violations.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
namespace harbor_081 {
    struct Pose { float x; float y; }; // OK: members are distinct
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    static float dist2(float dx,float dy){ return dx*dx + dy*dy; }
    void plan(){
        float x=0.0F, y=0.0F;                // NC
        float vx=0.0F, vy=0.0F;              // NC
        unsigned tasks=0U, alerts=0U;        // NC
        std::vector<Pose> slick{{1.2F,0.5F},{2.0F,-0.3F},{-0.8F,1.0F},{-1.5F,-0.6F}};
        for (std::size_t i=0;i<slick.size();++i){
            float dx = slick[i].x - x; float dy = slick[i].y - y;
            vx = clampf(vx + 0.2F*dx, -0.8F, 0.8F);
            vy = clampf(vy + 0.2F*dy, -0.8F, 0.8F);
            x += vx; y += vy; tasks++;
            if (dist2(dx,dy)>4.0F){ alerts++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" x="<<x<<" y="<<y<<" v=("<<vx<<","<<vy<<")\n"; }
        }
        std::cout<<"tasks="<<tasks<<" alerts="<<alerts<<"\n";
    }
}
int main(){ harbor_081::plan(); return 0; }
