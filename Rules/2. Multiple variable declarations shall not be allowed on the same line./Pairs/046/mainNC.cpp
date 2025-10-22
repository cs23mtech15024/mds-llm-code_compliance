// Context: Microgrid state-of-charge estimator

// ------ Non-Compliant Program (046_nc.cpp)
// Groups multiple declarators per declaration (8-0-1 violation).
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
namespace soc_046 {
    struct Pack { double soc; double target; }; // OK
    static double clamp(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    void estimate(){
        double soc=0.55, target=0.60;          // NC
        float eta=0.95F, loss=0.0F;            // NC
        unsigned it=0U, maxIt=8U;              // NC
        Pack p{soc,target};
        std::vector<double> log;
        for (; it<maxIt; ++it){
            double ch = 0.02 * (it%2U?1.0:-1.0);
            p.soc = clamp(p.soc + ch*eta - static_cast<double>(loss), 0.20, 0.95);
            log.push_back(p.soc);
            if ((it%3U)==0U){ loss += 0.001F; }
            if ((it%2U)==0U){ std::cout<<"it="<<it<<" soc="<<p.soc<<" loss="<<loss<<"\n"; }
        }
        std::cout<<"final="<<p.soc<<" mean="<<(log.empty()?0.0:std::accumulate(log.begin(),log.end(),0.0)/static_cast<double>(log.size()))<<"\n";
    }
}
int main(){ soc_046::estimate(); return 0; }
