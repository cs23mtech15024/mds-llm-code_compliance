// Context: Chemical plant pH neutralization tank controller

// ------ Compliant Program (096_c.cpp)
// Compliant: one declarator per declaration (8-0-1).
#include <iostream>
#include <vector>
#include <numeric>
namespace neutral_096 {
    struct Tank { double ph; double tgt; }; // OK
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void control(){
        double ph=6.2;                             // C
        double tgt=7.0;                            // C
        float acid=0.0F;                            // C
        float base=0.0F;                            // C
        int adds=0;                                  // C
        int alarms=0;                                // C
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
