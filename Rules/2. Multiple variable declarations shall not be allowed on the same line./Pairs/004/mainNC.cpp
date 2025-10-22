// Context: Warehouse robot SLAM pose tracker

// ------ Non-Compliant Program (004_nc.cpp)
// 8-0-1 violations are annotated with // NC.
#include <iostream>
#include <cmath>
#include <cstddef>
namespace slam_004 {
    struct Pose { float x; float y; float th; }; // OK
    static float wrap(float a){ while(a>3.14159F) a-=6.28318F; while(a<-3.14159F) a+=6.28318F; return a; }
    void update(){
        float x=0.0F, y=0.0F;             // NC
        float vx=0.1F, vy=0.0F;           // NC
        unsigned it=0U, maxIt=6U;         // NC
        Pose p{0.0F,0.0F,0.0F};
        for (; it<maxIt; ++it){
            p.x += vx; p.y += vy; p.th = wrap(p.th + 0.01F);
            if ((it%2U)==0U){ std::cout<<"i="<<it<<" x="<<p.x<<" y="<<p.y<<" th="<<p.th<<"\n"; }
        }
        std::cout<<"done it="<<it<<"/"<<maxIt<<"\n";
    }
}
int main(){ slam_004::update(); return 0; }
