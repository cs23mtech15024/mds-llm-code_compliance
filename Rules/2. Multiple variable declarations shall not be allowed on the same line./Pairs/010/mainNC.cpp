// Context: Spacecraft solar array power tracker

// ------ Non-Compliant Program (010_nc.cpp)
// 8-0-1 violations via multiple declarators.
#include <iostream>
#include <numeric>
#include <vector>
namespace pwr_010 {
    struct Telemetry { double w; double v; double a; }; // OK
    static double mean(const std::vector<double>& s){ return s.empty()?0.0:std::accumulate(s.begin(),s.end(),0.0)/static_cast<double>(s.size()); }
    void track(){
        double watts=0.0, volts=0.0;           // NC
        double amps=0.0, temp=0.0;             // NC
        unsigned it=0U, maxIt=10U;             // NC
        Telemetry t{0.0,0.0,0.0};
        std::vector<double> wlog;
        for (; it<maxIt; ++it){
            t.w += 10.0; t.v += 0.5; t.a = (t.v>0.0)?(t.w/t.v):0.0;
            wlog.push_back(t.w);
        }
        std::cout<<"W="<<t.w<<" V="<<t.v<<" A="<<t.a<<" Wavg="<<mean(wlog)
                 <<" it="<<it<<"/"<<maxIt<<"\n";
    }
}
int main(){ pwr_010::track(); return 0; }
