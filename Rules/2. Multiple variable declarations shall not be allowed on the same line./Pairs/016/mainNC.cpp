// Context: UAV camera gimbal stabilizer

// ------ Non-Compliant Program (016_nc.cpp)
// Multiple declarators present (8-0-1 violation).
#include <iostream>
#include <cmath>
namespace gimbal_016 {
    struct Ang { float r; float p; float y; }; // OK
    static float wrap(float a){ while(a>3.14159F) a-=6.28318F; while(a<-3.14159F) a+=6.28318F; return a; }
    void step(){
        float roll=0.0F, pitch=0.0F;           // NC
        float yaw=0.0F, drift=0.0F;            // NC
        unsigned frames=0U, drops=0U;          // NC
        Ang a{0.0F,0.0F,0.0F};
        for (unsigned i=0U;i<8U;++i){
            a.r = wrap(a.r + 0.01F); a.y = wrap(a.y - 0.02F);
            frames++; if ((i%3U)==0U) { drops++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" r="<<a.r<<" y="<<a.y<<"\n"; }
        }
        std::cout<<"frames="<<frames<<" drops="<<drops<<"\n";
    }
}
int main(){ gimbal_016::step(); return 0; }
