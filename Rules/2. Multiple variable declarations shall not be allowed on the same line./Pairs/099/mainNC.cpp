// Context: Autonomous rail yard switch matrix arbiter

// ------ Non-Compliant Program (099_nc.cpp)
// 8-0-1 violation using grouped declarators.
#include <iostream>
#include <deque>
#include <algorithm>
namespace yard_099 {
    struct Net { unsigned tracks; unsigned routes; }; // OK
    static unsigned clampu(unsigned v,unsigned lo,unsigned hi){ return std::max(lo,std::min(hi,v)); }
    void arbitrate(){
        unsigned tracks=7U, routes=3U;          // NC
        float bias=0.0F, gain=0.6F;             // NC
        int moves=0, conflicts=0;               // NC
        std::deque<unsigned> req{2,1,3,2,4,1,2,3};
        for (std::size_t i=0;i<req.size();++i){
            tracks = clampu(tracks + (req[i]>2?1U:0U), 5U, 12U);
            bias   = std::min(1.0F,std::max(0.0F, bias + (req[i]>2?0.2F:-0.1F)));
            if (bias>0.8F){ conflicts++; }
            moves += static_cast<int>(req[i]);
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" tr="<<tracks<<" bias="<<bias<<" moves="<<moves<<"\n"; }
        }
        std::cout<<"moves="<<moves<<" conflicts="<<conflicts<<"\n";
    }
}
int main(){ yard_099::arbitrate(); return 0; }
