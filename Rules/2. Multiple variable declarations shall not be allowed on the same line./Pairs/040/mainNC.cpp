// Context: Urban traffic light adaptive timing

// ------ Non-Compliant Program (040_nc.cpp)
// Uses multiple declarators in single declarations (8-0-1 violation).
#include <iostream>
#include <array>
#include <algorithm>
namespace signal_040 {
    struct Phase { unsigned cars; float gain; }; // OK
    static float clamp(float v){ return std::max(0.5F,std::min(1.5F,v)); }
    void adapt(){
        unsigned nS=20U, nE=15U;               // NC
        float bias=0.0F, gain=1.0F;            // NC
        int faults=0, rescales=0;              // NC
        std::array<unsigned,6U> counts{22,18,25,15,19,30};
        for (std::size_t i=0;i<counts.size();++i){
            nS += (i%2U)?1U:0U; nE += (i%2U)?0U:1U;
            gain = clamp(gain + 0.05F*(counts[i]>20U?1.0F:-1.0F));
            bias += (counts[i]>20U)?0.1F:-0.05F;
            if ((i%3U)==0U){ rescales++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" nS="<<nS<<" nE="<<nE<<" g="<<gain<<"\n"; }
        }
        std::cout<<"faults="<<faults<<" rescales="<<rescales<<"\n";
    }
}
int main(){ signal_040::adapt(); return 0; }
