// Context: Wind farm battery smoothing controller

// ------ Non-Compliant Program (085_nc.cpp)
// Groups declarators; violates MISRA C++ 8-0-1.
#include <iostream>
#include <vector>
#include <cmath>
namespace wind_085 {
    struct Store { float soc; float rate; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void smooth(){
        double p=3.5, tgt=4.0;                // NC
        float soc=0.6F, rate=0.0F;            // NC
        unsigned ticks=0U, trips=0U;          // NC
        std::vector<double> gust{4.6,3.9,4.2,3.4,4.8,3.6};
        for (std::size_t i=0;i<gust.size();++i){
            double e = tgt - p; rate = clampf(rate + static_cast<float>(e*0.2), -1.0F, 1.0F);
            soc = clampf(soc + rate*0.02F, 0.1F, 0.9F);
            p = 0.9*p + 0.1*gust[i] + static_cast<double>(rate)*0.1;
            if (soc<0.15F || soc>0.85F){ trips++; }
            ticks++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" p="<<p<<" soc="<<soc<<" r="<<rate<<"\n"; }
        }
        std::cout<<"ticks="<<ticks<<" trips="<<trips<<"\n";
    }
}
int main(){ wind_085::smooth(); return 0; }
