// Context: Industrial freezer temperature guard

// ------ Compliant Program (028_c.cpp)
// One declarator per declaration; same control logic preserved.
#include <iostream>
#include <algorithm>
namespace cold_028 {
    struct Pair { double a; double b; }; // OK
    static double lim(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void guard(){
        double tA=-18.0;                         // C
        double tB=-19.5;                         // C
        float drift=0.0F;                         // C
        float slope=0.0F;                         // C
        int open=0;                               // C
        int alerts=0;                             // C
        Pair p{tA,tB};
        for (unsigned i=0U;i<10U;++i){
            drift += 0.2F; slope = -0.05F; p.a = lim(p.a,-30.0, 5.0); p.b = lim(p.b,-30.0, 5.0);
            if (p.a>-15.0 || p.b>-15.0){ alerts++; }
            if ((i%3U)==0U){ open++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" a="<<p.a<<" b="<<p.b<<" d="<<drift<<" s="<<slope<<"\n"; }
        }
        std::cout<<"open="<<open<<" alerts="<<alerts<<"\n";
    }
}
int main(){ cold_028::guard(); return 0; }
