// Context: Airport baggage carousel jam detector

// ------ Compliant Program (092_c.cpp)
// Compliant: one declarator per declaration across the file.
#include <iostream>
#include <array>
#include <algorithm>
namespace carousel_092 {
    struct Drive { float speed; float tq; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void detect(){
        unsigned sensors=4U;                      // C
        unsigned trips=0U;                        // C
        float speed=0.8F;                         // C
        float torque=0.0F;                        // C
        int jams=0;                               // C
        int clears=0;                             // C
        std::array<float,8U> load{0.3F,0.6F,1.1F,0.4F,1.3F,0.5F,0.2F,1.4F};
        for (std::size_t i=0;i<load.size();++i){
            torque = clampf(torque + load[i]*0.3F, 0.0F, 1.6F);
            speed  = clampf(speed - load[i]*0.05F, 0.2F, 1.0F);
            if (torque>1.2F){ ++jams; } else { ++clears; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" sp="<<speed<<" tq="<<torque<<"\n"; }
        }
        std::cout<<"sensors="<<sensors<<" trips="<<trips<<" jams="<<jams<<" clears="<<clears<<"\n";
    }
}
int main(){ carousel_092::detect(); return 0; }
