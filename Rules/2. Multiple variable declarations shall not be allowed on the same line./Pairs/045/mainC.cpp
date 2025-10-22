// Context: Agricultural drone fertilization nozzle map

// ------ Compliant Program (045_c.cpp)
// Compliant version: one declarator per declaration throughout.
#include <iostream>
#include <vector>
#include <numeric>
namespace fert_045 {
    struct Cell { float a; float b; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    float avg(const std::vector<float>& v){ return v.empty()?0.0F:std::accumulate(v.begin(),v.end(),0.0F)/static_cast<float>(v.size()); }
    void map(){
        float flowA=0.2F;                         // C
        float flowB=0.2F;                         // C
        unsigned cells=0U;                        // C
        unsigned faults=0U;                       // C
        double scale=1.0;                         // C
        double bias=0.0;                          // C
        std::vector<float> zone{0.19F,0.20F,0.23F,0.18F};
        for (std::size_t i=0;i<zone.size();++i){
            flowA = clampf(zone[i]*static_cast<float>(scale)+static_cast<float>(bias),0.1F,0.3F);
            flowB = clampf(flowA*0.95F,0.1F,0.3F);
            cells++;
            if (flowA<0.15F){ faults++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" A="<<flowA<<" B="<<flowB<<"\n"; }
        }
        std::cout<<"cells="<<cells<<" faults="<<faults<<" Aavg="<<avg(zone)<<"\n";
    }
}
int main(){ fert_045::map(); return 0; }
