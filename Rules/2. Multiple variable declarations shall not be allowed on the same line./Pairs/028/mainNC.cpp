// Context: Industrial freezer temperature guard

// ------ Non-Compliant Program (028_nc.cpp)
// 8-0-1 breaches via multiple declarators per declaration.
#include <iostream>
#include <algorithm>
namespace cold_028 {
    struct Pair { double a; double b; }; // OK
    static double lim(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void guard(){
        double tA=-18.0, tB=-19.5;            // NC
        float drift=0.0F, slope=0.0F;         // NC
        int open=0, alerts=0;                 // NC
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
