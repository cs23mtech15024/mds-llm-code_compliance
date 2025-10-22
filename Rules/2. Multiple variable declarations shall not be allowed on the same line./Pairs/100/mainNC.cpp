// Context: Urban flood pump station capacity balancer

// ------ Non-Compliant Program (100_nc.cpp)
// Groups multiple declarators per declaration (// NC) — violates 8-0-1.
#include <iostream>
#include <vector>
#include <numeric>
namespace pump_100 {
    struct Station { double inflow; double out; }; // OK
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void balance(){
        double inflow=3.0, out=2.5;             // NC
        float pumpA=0.0F, pumpB=0.0F;           // NC
        unsigned steps=0U, alarms=0U;           // NC
        std::vector<double> rain{0.6,0.9,0.4,1.2,0.5,0.8};
        for (std::size_t i=0;i<rain.size();++i){
            inflow = clampd(inflow + rain[i]-0.3, 0.5, 6.0);
            pumpA  = std::min(1.0F,std::max(0.0F, pumpA + static_cast<float>((inflow-out)*0.15)));
            pumpB  = std::min(1.0F,std::max(0.0F, pumpB + static_cast<float>((inflow-out)*0.10)));
            out    = clampd(out + static_cast<double>(pumpA)*0.5 + static_cast<double>(pumpB)*0.3, 0.0, 6.0);
            if (inflow-out>2.0){ ++alarms; }
            ++steps;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" in="<<inflow<<" out="<<out<<" A="<<pumpA<<" B="<<pumpB<<"\n"; }
        }
        std::cout<<"steps="<<steps<<" alarms="<<alarms<<" rain_mean="<<mean(rain)<<"\n";
    }
}
int main(){ pump_100::balance(); return 0; }
