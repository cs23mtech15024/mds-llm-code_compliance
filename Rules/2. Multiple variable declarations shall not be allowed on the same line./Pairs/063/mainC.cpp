// Context: Factory conveyor vision reject gate

// ------ Compliant Program (063_c.cpp)
// One declarator per declaration (MISRA C++ 8-0-1 compliant).
#include <iostream>
#include <vector>
#include <algorithm>
namespace gate_063 {
    struct Stats { unsigned good; unsigned bad; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void reject(){
        unsigned good=0U;                         // C
        unsigned bad=0U;                          // C
        float conf=0.0F;                          // C
        float thr=0.85F;                          // C
        bool jam=false;                           // C
        bool reject=false;                        // C
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
