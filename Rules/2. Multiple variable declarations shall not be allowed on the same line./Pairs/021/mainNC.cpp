// Context: Warehouse AGV path follower

// ------ Non-Compliant Program (021_nc.cpp)
// Rule: MISRA C++ 8-0-1 — a declaration shall contain no more than one declarator.
// This file purposefully groups multiple declarators (// NC) to show violations.
#include <iostream>
#include <vector>
#include <cmath>
#include <cstddef>
namespace agv_021 {
    struct Pose { float x; float y; float th; }; // OK: members are separate
    static float wrap(float a){ while(a>3.14159F) a-=6.28318F; while(a<-3.14159F) a+=6.28318F; return a; }
    static float clamp(float v,float lo,float hi){ return v<lo?lo:(v>hi?hi:v); }
    void follow(){
        float x=0.0F, y=0.0F;                 // NC
        float vx=0.10F, vy=0.00F;             // NC
        unsigned steps=0U, maxS=12U;          // NC
        Pose p{0.0F,0.0F,0.0F};
        std::vector<Pose> wp{{0.5F,0.0F,0.0F},{1.0F,0.0F,0.0F},{1.0F,0.5F,1.57F}};
        for (std::size_t i=0U; i<wp.size(); ++i){
            float ex = wp[i].x - p.x; float ey = wp[i].y - p.y;
            vx = clamp(ex*0.6F,-0.2F,0.2F); vy = clamp(ey*0.6F,-0.2F,0.2F);
            p.x += vx; p.y += vy; p.th = wrap(wp[i].th);
            x = p.x; y = p.y; steps++;
            if ((i%1U)==0U){ std::cout<<"i="<<i<<" x="<<x<<" y="<<y<<" th="<<p.th<<"\n"; }
            if (steps>=maxS){ break; }
        }
        std::cout<<"steps="<<steps<<" maxS="<<maxS<<"\n";
    }
}
int main(){ agv_021::follow(); return 0; }
