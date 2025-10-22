// Context: Swarm drone collision avoidance

// ------ Compliant Program (056_c.cpp)
// Compliant: each declaration contains only one declarator.
#include <iostream>
#include <vector>
#include <cmath>
namespace swarm_056 {
    struct Pose { float x; float y; }; // OK
    static float dist2(float a,float b){ return a*a+b*b; }
    void avoid(){
        float x=0.0F;                             // C
        float y=0.0F;                             // C
        float vx=0.1F;                            // C
        float vy=-0.1F;                           // C
        unsigned peers=5U;                        // C
        unsigned alerts=0U;                       // C
        std::vector<Pose> others{{0.3F,0.0F},{-0.2F,0.2F},{0.1F,-0.1F}};
        for (std::size_t i=0;i<others.size();++i){
            x+=vx; y+=vy;
            float dx=x-others[i].x;
            float dy=y-others[i].y;
            if (dist2(dx,dy)<0.05F){ alerts++; vx=-vx; vy=-vy; }
            if ((i%1U)==0U){ std::cout<<"i="<<i<<" x="<<x<<" y="<<y<<" a="<<alerts<<"\n"; }
        }
        std::cout<<"peers="<<peers<<" alerts="<<alerts<<"\n";
    }
}
int main(){ swarm_056::avoid(); return 0; }