// Context: High-speed rail pantograph contact monitor

// ------ Non-Compliant Program (084_nc.cpp)
// Declares multiple declarators per declaration — violates 8-0-1.
#include <iostream>
#include <vector>
#include <numeric>
namespace rail_084 {
    struct Contact { float f; float rate; }; // OK
    float avg(const std::vector<float>& v){ return v.empty()?0.0F:std::accumulate(v.begin(),v.end(),0.0F)/static_cast<float>(v.size()); }
    void monitor(){
        float force=0.0F, rate=0.0F;           // NC
        float thr=90.0F, margin=5.0F;          // NC
        unsigned hits=0U, alarms=0U;           // NC
        std::vector<float> shocks{82.0F,88.0F,93.0F,97.0F,85.0F};
        for (std::size_t i=0;i<shocks.size();++i){
            force = shocks[i];
            rate  = 0.6F*rate + 0.4F*(force-85.0F);
            if (force>(thr+margin)){ ++hits; }
            if (hits>2U){ ++alarms; hits=0U; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" f="<<force<<" r="<<rate<<"\n"; }
        }
        std::cout<<"hits="<<hits<<" alarms="<<alarms<<" mean="<<avg(shocks)<<"\n";
    }
}
int main(){ rail_084::monitor(); return 0; }
