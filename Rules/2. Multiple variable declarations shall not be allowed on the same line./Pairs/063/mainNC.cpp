// Context: Factory conveyor vision reject gate

// ------ Non-Compliant Program (063_nc.cpp)
// 8-0-1 violations: multi-declarator lines marked // NC.
#include <iostream>
#include <vector>
#include <algorithm>
namespace gate_063 {
    struct Stats { unsigned good; unsigned bad; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void reject(){
        unsigned good=0U, bad=0U;                // NC
        float conf=0.0F, thr=0.85F;              // NC
        bool jam=false, reject=false;            // NC
        std::vector<float> confs{0.92F,0.83F,0.88F,0.97F,0.80F};
        for (std::size_t i=0;i<confs.size();++i){
            conf = clampf(confs[i],0.0F,1.0F); reject = (conf<thr);
            if (reject){ ++bad; } else { ++good; }
            if (reject && (i%3U)==0U){ jam=true; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" c="<<conf<<" rej="<<reject<<"\n"; }
        }
        std::cout<<"good="<<good<<" bad="<<bad<<" jam="<<jam<<"\n";
    }
}
int main(){ gate_063::reject(); return 0; }
