// Context: High-speed rail pantograph contact monitor

// ------ Non-Compliant Program (047_nc.cpp)
// Multiple declarators on one line -> 8-0-1 violation.
#include <iostream>
#include <vector>
#include <algorithm>
namespace pano_047 {
    struct Contact { float f; float v; }; // OK
    static float lim(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void monitor(){
        float force=85.0F, vib=0.0F;           // NC
        unsigned hits=0U, faults=0U;           // NC
        bool ice=false, arc=false;             // NC
        std::vector<float> bursts{0.2F,0.4F,0.1F,0.6F,0.3F};
        for (std::size_t i=0;i<bursts.size();++i){
            vib = lim(vib + bursts[i], 0.0F, 2.0F);
            if (vib>0.5F){ hits++; }
            if (vib>1.0F){ faults++; arc=true; }
            if ((i%3U)==0U){ ice=!ice; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" vib="<<vib<<" hits="<<hits<<" arc="<<arc<<"\n"; }
        }
        std::cout<<"hits="<<hits<<" faults="<<faults<<" ice="<<ice<<"\n";
    }
}
int main(){ pano_047::monitor(); return 0; }
