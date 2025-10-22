// Context: Autonomous warehouse shuttle traffic coordinator

// ------ Non-Compliant Program (072_nc.cpp)
// Demonstrates 8-0-1 violations via grouped declarators.
#include <iostream>
#include <deque>
#include <algorithm>
namespace shuttle_072 {
    struct Net { unsigned lanes; unsigned docks; }; // OK
    static unsigned clampu(unsigned v,unsigned lo,unsigned hi){ return std::max(lo,std::min(hi,v)); }
    void route(){
        unsigned lanes=4U, docks=6U;           // NC
        float bias=0.0F, gain=0.5F;            // NC
        int reroutes=0, stalls=0;              // NC
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
