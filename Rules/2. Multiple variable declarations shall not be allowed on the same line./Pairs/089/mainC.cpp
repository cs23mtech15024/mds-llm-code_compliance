// Context: Microgrid black-start sequencer

// ------ Compliant Program (089_c.cpp)
// Compliant: one declarator per declaration across the file.
#include <iostream>
#include <vector>
#include <algorithm>
namespace start_089 {
    struct Step { unsigned gens; unsigned loads; }; // OK
    void start(){
        unsigned gens=2U;                           // C
        unsigned loads=5U;                          // C
        float freq=0.0F;                            // C
        float volt=0.0F;                            // C
        int steps=0;                                 // C
        int fails=0;                                 // C
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
