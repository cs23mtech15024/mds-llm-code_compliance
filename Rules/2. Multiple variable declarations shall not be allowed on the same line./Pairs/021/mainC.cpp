// Context: Warehouse AGV path follower

// ------ Compliant Program (021_c.cpp)
// Fix: single declarator per declaration; same behavior as noncompliant.
#include <iostream>
#include <vector>
#include <cmath>
#include <cstddef>
namespace agv_021 {
    struct Pose { float x; float y; float th; }; // OK
    static float wrap(float a){ while(a>3.14159F) a-=6.28318F; while(a<-3.14159F) a+=6.28318F; return a; }
    static float clamp(float v,float lo,float hi){ return v<lo?lo:(v>hi?hi:v); }
    void follow(){
        float x=0.0F;                          // C
        float y=0.0F;                          // C
        float vx=0.10F;                        // C
        float vy=0.00F;                        // C
        unsigned steps=0U;                     // C
        unsigned maxS=12U;                     // C
        Pose p{0.0F,0.0F,0.0F};
        std::vector<Pose> wp{{0.5F,0.0F,0.0F},{1.0F,0.0F,0.0F},{1.0F,0.5F,1.57F}};
        for (std::size_t i=0U; i<wp.size(); ++i){
            float ex = wp[i].x - p.x;
            float ey = wp[i].y - p.y;
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