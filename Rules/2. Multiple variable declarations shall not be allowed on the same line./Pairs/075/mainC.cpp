// Context: Drone swarm perimeter sentry ring

// ------ Compliant Program (075_c.cpp)
// Compliant: single declarator per declaration across the file.
#include <iostream>
#include <vector>
#include <cmath>
namespace ring_075 {
    struct Drone { float r; float ang; }; // OK
    static float wrap(float a){ while(a>3.14159F)a-=6.28318F; while(a<-3.14159F)a+=6.28318F; return a; }
    void patrol(){
        float r=50.0F;                            // C
        float ang=0.0F;                           // C
        float v=2.0F;                             // C
        float turn=0.0F;                          // C
        unsigned drones=6U;                        // C
        unsigned flags=0U;                         // C
        std::vector<float> wind{0.1F,-0.2F,0.0F,0.3F,-0.1F};
        for (std::size_t i=0;i<wind.size();++i){
            turn = 0.05F*wind[i]; ang = wrap(ang + turn);
            r += (i%2U?0.5F:-0.2F); if (r<40.0F){ flags++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" r="<<r<<" ang="<<ang<<"\n"; }
        }
        std::cout<<"drones="<<drones<<" flags="<<flags<<"\n";
    }
}
int main(){ ring_075::patrol(); return 0; }
