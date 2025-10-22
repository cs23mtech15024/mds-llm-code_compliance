// Context: Hospital HVAC surgical theater pressure control

// ------ Compliant Program (086_c.cpp)
// Compliant: one declarator per declaration across the file.
#include <iostream>
#include <array>
#include <algorithm>
namespace hvac_086 {
    struct Zone { double room; double hall; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void regulate(){
        double room=2.0;                          // C
        double corridor=0.5;                      // C
        float fan=0.0F;                           // C
        float damper=0.0F;                        // C
        unsigned t=0U;                            // C
        unsigned alarms=0U;                       // C
        std::array<double,8U> dist{0.2,-0.1,0.3,-0.2,0.1,0.1,-0.1,0.0};
        for (std::size_t i=0;i<dist.size();++i){
            double dp = room - corridor;
            fan = std::min(1.0F,std::max(0.0F,fan + static_cast<float>((2.0-dp)*0.1)));
            damper = std::min(1.0F,std::max(0.0F,damper + static_cast<float>((dp-0.5)*0.1)));
            room = clampd(room + dist[i] + static_cast<double>(fan)*0.1, 1.0, 3.5);
            corridor = clampd(corridor + 0.05 - static_cast<double>(damper)*0.08, 0.2, 2.5);
            if (room-corridor<0.2){ alarms++; }
            t++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" room="<<room<<" hall="<<corridor<<"\n"; }
        }
        std::cout<<"t="<<t<<" alarms="<<alarms<<"\n";
    }
}
int main(){ hvac_086::regulate(); return 0; }
