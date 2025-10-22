// Context: Power substation thermal monitor

// ------ Compliant Program (017_c.cpp)
// One declarator per declaration.
#include <iostream>
#include <algorithm>
namespace sub_017 {
    struct Therm { double cab; double bus; }; // OK
    static double limit(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void check(){
        double tCab=36.5;                      // C
        double tBus=38.0;                      // C
        float rmsA=100.0F;                     // C
        float rmsB=98.5F;                      // C
        bool fan=false;                         // C
        bool alert=false;                       // C
        Therm t{tCab,tBus};
        t.cab = limit(t.cab, -20.0, 85.0); t.bus = limit(t.bus, -20.0, 85.0);
        if (t.bus>40.0){ alert=true; fan=true; }
        std::cout<<"cab="<<t.cab<<" bus="<<t.bus<<" fan="<<fan<<" alert="<<alert<<"\n";
    }
}
int main(){ sub_017::check(); return 0; }
