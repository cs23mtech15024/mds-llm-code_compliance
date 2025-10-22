// Context: Arctic research station power dispatcher

// ------ Compliant Program (071_c.cpp)
// Fix: use single-declarator declarations everywhere (compliant with 8-0-1).
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
namespace arctic_071 {
    struct Mix { double solar; double wind; float bat; float diesel; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    static double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void dispatch(){
        double solar=1.2;                          // C
        double wind=2.1;                           // C
        float battery=0.6F;                        // C
        float diesel=0.0F;                         // C
        unsigned ticks=0U;                         // C
        unsigned alarms=0U;                        // C
        Mix m{solar,wind,battery,diesel};
        std::vector<double> sTrace;
        for (unsigned k=0U;k<14U;++k){
            double load = 2.5 + (k%3==0?0.8:-0.3);
            double renew = m.solar + m.wind;
            double gap = load - renew;
            m.bat = static_cast<float>(clampd(m.bat - gap*0.05, 0.1, 0.9));
            if (gap>0.0){ m.diesel = static_cast<float>(clampd(m.diesel + gap*0.2, 0.0, 2.0)); }
            m.solar = clampd(m.solar + 0.05*(k%2?1.0:-1.0), 0.5, 2.5);
            m.wind  = clampd(m.wind  + 0.10*(k%3?1.0:-1.0), 0.2, 3.0);
            ticks++; if (m.diesel>1.8F){ alarms++; }
            sTrace.push_back(m.solar);
            if ((k%2U)==0U){
                std::cout<<"k="<<k<<" load="<<load<<" R="<<renew<<" bat="<<m.bat<<" d="<<m.diesel<<"\n";
            }
        }
        std::cout<<"ticks="<<ticks<<" alarms="<<alarms<<" solar_mean="<<mean(sTrace)<<"\n";
    }
}
int main(){ arctic_071::dispatch(); return 0; }
