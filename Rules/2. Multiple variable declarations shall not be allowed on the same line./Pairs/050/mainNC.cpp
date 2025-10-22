// Context: Planetary rover slip detection module

// ------ Non-Compliant Program (050_nc.cpp)
// 8-0-1 violated by grouping declarators.
#include <iostream>
#include <vector>
#include <cmath>
namespace rover_050 {
    struct Wheel { float omega; float v; }; // OK
    static float slip(float om,float v){ return (om*0.1F - v); }
    void detect(){
        float omega=5.0F, v=0.5F;              // NC
        float mu=0.6F, slipVal=0.0F;           // NC
        unsigned frames=0U, alarms=0U;         // NC
        std::vector<float> tr{5.1F,5.3F,5.5F,5.2F,5.0F};
        for (std::size_t i=0;i<tr.size();++i){
            omega = tr[i]; slipVal = slip(omega,v);
            if (slipVal>mu*0.1F){ alarms++; }
            frames++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" om="<<omega<<" s="<<slipVal<<" alarms="<<alarms<<"\n"; }
        }
        std::cout<<"frames="<<frames<<" alarms="<<alarms<<"\n";
    }
}
int main(){ rover_050::detect(); return 0; }
