// Context: Smart building elevator load leveler

// ------ Compliant Program (044_c.cpp)
// Compliant rewrite: one declarator per declaration.
#include <iostream>
#include <deque>
#include <algorithm>
namespace lift_044 {
    struct Car { int load; int limit; }; // OK
    static int clampi(int v,int lo,int hi){ return std::max(lo,std::min(hi,v)); }
    void level(){
        int load=0;                              // C
        int limit=1200;                          // C
        float bias=0.0F;                         // C
        float rate=0.0F;                         // C
        bool slow=false;                         // C
        bool stop=false;                         // C
        Car c{load,limit};
        std::deque<int> deltas{200,150,-50,300,-400,100};
        for (std::size_t i=0;i<deltas.size();++i){
            c.load = clampi(c.load + deltas[i], 0, c.limit);
            rate += (deltas[i]>0?0.05F:-0.03F); bias += 0.01F;
            if (c.load>c.limit-50){ slow=true; }
            if (c.load==c.limit){ stop=true; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" load="<<c.load<<" rate="<<rate<<" slow="<<slow<<"\n"; }
        }
        std::cout<<"stop="<<stop<<" bias="<<bias<<"\n";
    }
}
int main(){ lift_044::level(); return 0; }
