// Context: Mars rover wheel slip compensator

// ------ Compliant Program (094_c.cpp)
// Single-declarator declarations everywhere (8-0-1 compliant).
#include <iostream>
#include <deque>
#include <algorithm>
namespace rover_094 {
    struct Slip { double s; float cmd; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void compensate(){
        double slip=0.0;                         // C
        double set=0.15;                         // C
        float gain=0.4F;                          // C
        float cmd=0.0F;                           // C
        int events=0;                              // C
        int limits=0;                              // C
        std::deque<double> terrain{0.05,0.18,0.22,0.10,0.30,0.12};
        for (std::size_t i=0;i<terrain.size();++i){
            slip = clampd(terrain[i], 0.0, 0.6);
            double e = set - slip;
            cmd = std::min(1.0F,std::max(0.0F, cmd + static_cast<float>(gain*e)));
            if (cmd>0.85F){ ++limits; }
            ++events;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" slip="<<slip<<" cmd="<<cmd<<"\n"; }
        }
        std::cout<<"events="<<events<<" limits="<<limits<<"\n";
    }
}
int main(){ rover_094::compensate(); return 0; }
