// Context: High-speed rail pantograph contact monitor

// ------ Compliant Program (047_c.cpp)
// Compliant rewrite using one declarator per declaration.
#include <iostream>
#include <vector>
#include <algorithm>
namespace pano_047 {
    struct Contact { float f; float v; }; // OK
    static float lim(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void monitor(){
        float force=85.0F;                        // C
        float vib=0.0F;                           // C
        unsigned hits=0U;                         // C
        unsigned faults=0U;                       // C
        bool ice=false;                           // C
        bool arc=false;                           // C
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
