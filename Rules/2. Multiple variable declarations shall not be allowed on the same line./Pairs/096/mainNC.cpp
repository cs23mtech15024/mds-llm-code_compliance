// Context: Chemical plant pH neutralization tank controller

// ------ Non-Compliant Program (096_nc.cpp)
// 8-0-1 violations: grouped declarators per declaration.
#include <iostream>
#include <vector>
#include <numeric>
namespace neutral_096 {
    struct Tank { double ph; double tgt; }; // OK
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void control(){
        double ph=6.2, tgt=7.0;                 // NC
        float acid=0.0F, base=0.0F;             // NC
        int adds=0, alarms=0;                   // NC
        std::vector<double> dist{-0.1,0.2,0.3,-0.2,0.0,0.4};
        for (std::size_t i=0;i<dist.size();++i){
            ph = clampd(ph + dist[i], 5.0, 9.0);
            base = std::min(1.0F,std::max(0.0F, base + static_cast<float>((tgt-ph)*0.1)));
            acid = std::min(1.0F,std::max(0.0F, acid + static_cast<float>((ph-tgt)*0.1)));
            if (ph<6.5 || ph>7.5){ alarms++; }
            adds++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" ph="<<ph<<" a="<<acid<<" b="<<base<<"\n"; }
        }
        std::cout<<"adds="<<adds<<" alarms="<<alarms<<" mean="<<mean(dist)<<"\n";
    }
}
int main(){ neutral_096::control(); return 0; }
