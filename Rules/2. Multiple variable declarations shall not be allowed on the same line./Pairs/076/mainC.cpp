// Context: Marine buoy wave spectral estimator

// ------ Compliant Program (076_c.cpp)
// Compliant: one declarator per declaration.
#include <iostream>
#include <vector>
#include <numeric>
namespace buoy_076 {
    struct Acc { float ax; float ay; float az; }; // OK
    float avg(const std::vector<float>& v){ return v.empty()?0.0F:std::accumulate(v.begin(),v.end(),0.0F)/static_cast<float>(v.size()); }
    void estimate(){
        float ax=0.0F;                            // C
        float ay=0.0F;                            // C
        float az=0.0F;                            // C
        float dt=0.05F;                           // C
        unsigned n=0U;                            // C
        unsigned spikes=0U;                       // C
        std::vector<float> s{0.1F,-0.1F,0.2F,-0.2F,0.3F};
        for (std::size_t i=0;i<s.size();++i){
            ax += s[i]; ay -= s[i]*0.8F; az += s[i]*0.5F; n++;
            if (std::fabs(s[i])>0.25F){ spikes++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" ax="<<ax<<" ay="<<ay<<" az="<<az<<"\n"; }
        }
        std::cout<<"n="<<n<<" spikes="<<spikes<<" mean="<<avg(s)<<"\n";
    }
}
int main(){ buoy_076::estimate(); return 0; }
