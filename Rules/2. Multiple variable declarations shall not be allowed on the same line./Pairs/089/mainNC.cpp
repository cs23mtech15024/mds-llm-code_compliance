// Context: Microgrid black-start sequencer

// ------ Non-Compliant Program (089_nc.cpp)
// 8-0-1 violation via grouped declarators.
#include <iostream>
#include <vector>
#include <algorithm>
namespace start_089 {
    struct Step { unsigned gens; unsigned loads; }; // OK
    void start(){
        unsigned gens=2U, loads=5U;            // NC
        float freq=0.0F, volt=0.0F;            // NC
        int steps=0, fails=0;                  // NC
        std::vector<int> seq{1,0,1,1,0,1,1,1};
        for (std::size_t i=0;i<seq.size();++i){
            if (seq[i]==1){ gens++; volt += 0.2F; } else { loads++; freq += 0.1F; }
            if (volt>1.2F || freq>1.0F){ fails++; }
            steps++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" g="<<gens<<" l="<<loads<<" f="<<freq<<" v="<<volt<<"\n"; }
        }
        std::cout<<"steps="<<steps<<" fails="<<fails<<"\n";
    }
}
int main(){ start_089::start(); return 0; }
