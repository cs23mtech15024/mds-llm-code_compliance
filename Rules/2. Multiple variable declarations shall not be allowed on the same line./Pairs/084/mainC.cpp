// Context: High-speed rail pantograph contact monitor

// ------ Compliant Program (084_c.cpp)
// Compliant rewrite using single-declarator declarations.
#include <iostream>
#include <vector>
#include <numeric>
namespace rail_084 {
    struct Contact { float f; float rate; }; // OK
    float avg(const std::vector<float>& v){ return v.empty()?0.0F:std::accumulate(v.begin(),v.end(),0.0F)/static_cast<float>(v.size()); }
    void monitor(){
        float force=0.0F;                        // C
        float rate=0.0F;                         // C
        float thr=90.0F;                         // C
        float margin=5.0F;                       // C
        unsigned hits=0U;                        // C
        unsigned alarms=0U;                      // C
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
