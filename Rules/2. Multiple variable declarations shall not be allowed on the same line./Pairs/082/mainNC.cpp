// Context: Urban traffic adaptive signal phasing

// ------ Non-Compliant Program (082_nc.cpp)
// Groups multiple declarators per declaration — violates MISRA C++ 8-0-1.
#include <iostream>
#include <deque>
#include <algorithm>
namespace city_082 {
    struct Phase { unsigned n; unsigned e; }; // OK
    static unsigned clipu(unsigned v,unsigned lo,unsigned hi){ return std::max(lo,std::min(hi,v)); }
    void phase(){
        unsigned north=12U, east=8U;           // NC
        float bias=0.4F, gain=0.2F;            // NC
        int cycles=0, holds=0;                 // NC
        std::deque<unsigned> qN{10,13,15,9,8,14,16,11};
        for (std::size_t i=0;i<qN.size();++i){
            north = clipu(north + (qN[i]>12?1U:0U), 6U, 20U);
            bias  = std::max(0.0F,std::min(1.0F,bias + (qN[i]>12?0.1F:-0.05F)));
            if (bias>0.7F){ holds++; }
            cycles++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" north="<<north<<" bias="<<bias<<"\n"; }
        }
        std::cout<<"cycles="<<cycles<<" holds="<<holds<<"\n";
    }
}
int main(){ city_082::phase(); return 0; }
