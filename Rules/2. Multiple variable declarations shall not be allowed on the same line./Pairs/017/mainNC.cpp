// Context: Power substation thermal monitor

// ------ Non-Compliant Program (017_nc.cpp)
// Grouped declarators violate 8-0-1.
#include <iostream>
#include <algorithm>
namespace sub_017 {
    struct Therm { double cab; double bus; }; // OK
    static double limit(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void check(){
        double tCab=36.5, tBus=38.0;           // NC
        float rmsA=100.0F, rmsB=98.5F;         // NC
        bool fan=false, alert=false;           // NC
        Therm t{tCab,tBus};
        t.cab = limit(t.cab, -20.0, 85.0); t.bus = limit(t.bus, -20.0, 85.0);
        if (t.bus>40.0){ alert=true; fan=true; }
        std::cout<<"cab="<<t.cab<<" bus="<<t.bus<<" fan="<<fan<<" alert="<<alert<<"\n";
    }
}
int main(){ sub_017::check(); return 0; }
