// Context: Autonomous warehouse shuttle traffic coordinator

// ------ Compliant Program (072_c.cpp)
// Compliant: one declarator per declaration throughout.
#include <iostream>
#include <deque>
#include <algorithm>
namespace shuttle_072 {
    struct Net { unsigned lanes; unsigned docks; }; // OK
    static unsigned clampu(unsigned v,unsigned lo,unsigned hi){ return std::max(lo,std::min(hi,v)); }
    void route(){
        unsigned lanes=4U;                         // C
        unsigned docks=6U;                         // C
        float bias=0.0F;                           // C
        float gain=0.5F;                           // C
        int reroutes=0;                            // C
        int stalls=0;                              // C
        std::deque<unsigned> bursts{5,7,4,9,6,8};
        for (std::size_t i=0;i<bursts.size();++i){
            lanes = clampu(lanes + (bursts[i]>6?1U:0U), 3U, 12U);
            bias  = std::max(0.0F,std::min(1.0F,bias + (bursts[i]>6?0.1F:-0.05F)));
            if (bias>0.7F){ reroutes++; }
            if ((i%3U)==0U){ stalls += (gain>0.4F)?0:1; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" lanes="<<lanes<<" bias="<<bias<<"\n"; }
        }
        std::cout<<"reroutes="<<reroutes<<" stalls="<<stalls<<"\n";
    }
}
int main(){ shuttle_072::route(); return 0; }
