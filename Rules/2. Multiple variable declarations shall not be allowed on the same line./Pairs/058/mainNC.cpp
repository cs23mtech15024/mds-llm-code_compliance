// Context: Industrial robot torque observer calibrator

// ------ Non-Compliant Program (058_nc.cpp)
// 8-0-1 violation by grouping declarators.
#include <iostream>
#include <vector>
#include <numeric>
namespace torque_058 {
    struct Obs { double tau; double bias; }; // OK
    double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void calibrate(){
        double tau=0.0, bias=0.0;              // NC
        float alpha=0.1F, beta=0.0F;           // NC
        unsigned it=0U, maxIt=12U;             // NC
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
int main(){ torque_058::calibrate(); return 0; }
