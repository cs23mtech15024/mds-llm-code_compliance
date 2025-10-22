// Context: Electric scooter fleet charger balancer

// ------ Non-Compliant Program (079_nc.cpp)
// Declares multiple declarators per declaration — violates 8-0-1.
#include <iostream>
#include <vector>
#include <numeric>
namespace fleet_079 {
    struct Hub { unsigned plugs; unsigned bays; }; // OK
    static float clampf(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    float mean(const std::vector<float>& v){ return v.empty()?0.0F:std::accumulate(v.begin(),v.end(),0.0F)/static_cast<float>(v.size()); }
    void balance(){
        unsigned plugs=12U, bays=6U;            // NC
        float load=0.0F, bias=0.0F;             // NC
        int moves=0, faults=0;                  // NC
        std::vector<float> q{0.6F,0.9F,1.2F,0.8F,0.7F,1.1F};
        for (std::size_t i=0;i<q.size();++i){
            load = clampf(load + (q[i]-0.8F)*0.4F, 0.0F, 1.5F);
            bias = clampf(bias + (load>1.0F?0.1F:-0.05F), 0.0F, 1.0F);
            if (load>1.3F){ faults++; }
            if (q[i]>1.0F){ moves++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" load="<<load<<" bias="<<bias<<"\n"; }
        }
        std::cout<<"moves="<<moves<<" faults="<<faults<<" mean="<<mean(q)<<"\n";
    }
}
int main(){ fleet_079::balance(); return 0; }
