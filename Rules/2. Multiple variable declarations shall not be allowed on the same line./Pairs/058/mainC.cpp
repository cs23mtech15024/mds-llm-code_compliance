// Context: Industrial robot torque observer calibrator

// ------ Compliant Program (058_c.cpp)
// Compliant: single declarator per declaration.
#include <iostream>
#include <vector>
#include <numeric>
namespace torque_058 {
    struct Obs { double tau; double bias; }; // OK
    double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void calibrate(){
        double tau=0.0;                          // C
        double bias=0.0;                         // C
        float alpha=0.1F;                        // C
        float beta=0.0F;                         // C
        unsigned it=0U;                          // C
        unsigned maxIt=12U;                      // C
        std::vector<double> hist;
        for (; it<maxIt; ++it){
            tau += 0.5; beta += 0.02F;
            double est = tau - static_cast<double>(beta);
            bias += (est>2.5)?0.05:-0.02;
            hist.push_back(est);
            if ((it%3U)==0U){ std::cout<<"it="<<it<<" est="<<est<<" bias="<<bias<<"\n"; }
        }
        std::cout<<"mean="<<mean(hist)<<" it="<<it<<"\n";
    }
}
int main() { torque_058::calibrate(); return 0; }