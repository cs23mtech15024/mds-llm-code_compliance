// Context: Precision agriculture variable-rate sprayer

// ------ Compliant Program (087_c.cpp)
// Compliant: single-declarator declarations throughout.
#include <iostream>
#include <vector>
#include <numeric>
namespace spray_087 {
    struct Pass { float rate; float bias; }; // OK
    float mean(const std::vector<float>& v){ return v.empty()?0.0F:std::accumulate(v.begin(),v.end(),0.0F)/static_cast<float>(v.size()); }
    void apply(){
        float speed=2.5F;                        // C
        float width=12.0F;                       // C
        float rate=0.0F;                          // C
        float bias=0.0F;                          // C
        unsigned zones=8U;                        // C
        unsigned faults=0U;                       // C
        std::vector<float> idx{0.3F,0.7F,0.4F,0.9F,0.2F,0.6F};
        for (std::size_t i=0;i<idx.size();++i){
            rate = std::min(1.0F,std::max(0.0F, rate + (idx[i]-0.5F)*0.2F));
            bias = std::min(1.0F,std::max(0.0F, bias + (rate-0.5F)*0.1F));
            if (rate>0.9F){ faults++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" rate="<<rate<<" bias="<<bias<<"\n"; }
        }
        std::cout<<"zones="<<zones<<" faults="<<faults<<" mean="<<mean(idx)<<"\n";
    }
}
int main(){ spray_087::apply(); return 0; }
