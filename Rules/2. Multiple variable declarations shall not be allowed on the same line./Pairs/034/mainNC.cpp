// Context: Warehouse HVAC damper controller

// ------ Non-Compliant Program (034_nc.cpp)
// Intentionally groups declarators; breaks 8-0-1.
#include <iostream>
#include <algorithm>
namespace hvac_034 {
    struct Damper { float pos; float rate; }; // OK
    static float bound(float v){ return std::max(0.0F,std::min(1.0F,v)); }
    void loop(){
        float open=0.2F, rate=0.0F;            // NC
        bool heat=false, cool=false;           // NC
        int cmd=0, alarms=0;                   // NC
        Damper d{open, rate};
        for (int i=0;i<12;++i){
            cmd = (i%3==0)?1:((i%3==1)?-1:0);
            d.rate += 0.05F*static_cast<float>(cmd);
            d.pos = bound(d.pos + d.rate);
            if (d.pos>0.9F){ cool=true; }
            if (d.pos<0.1F){ heat=true; }
            if ((i%4)==0){ std::cout<<"i="<<i<<" pos="<<d.pos<<" rate="<<d.rate<<"\n"; }
        }
        std::cout<<"heat="<<heat<<" cool="<<cool<<" alarms="<<alarms<<"\n";
    }
}
int main(){ hvac_034::loop(); return 0; }
