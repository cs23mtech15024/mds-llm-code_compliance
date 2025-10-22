// Context: Pharmaceutical reactor PH controller

// ------ Non-Compliant Program (033_nc.cpp)
// Multiple declarators in single declarations -> violation of 8-0-1.
#include <iostream>
#include <vector>
#include <numeric>
namespace ph_033 {
    struct Titrant { double acid; double base; }; // OK
    static double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void control(){
        double ph=7.0, target=7.2;              // NC
        double acid=0.0, base=0.0;              // NC
        unsigned it=0U, maxIt=8U;               // NC
        Titrant tr{0.0,0.0};
        std::vector<double> phlog;
        for (; it<maxIt; ++it){
            double err = target - ph;
            acid += (err<0.0)?-err*0.1:0.0; base += (err>0.0)?err*0.1:0.0;
            ph += (base - acid)*0.02; phlog.push_back(ph);
            if ((it%2U)==0U){ std::cout<<"i="<<it<<" ph="<<ph<<" err="<<err<<"\n"; }
        }
        std::cout<<"ph_avg="<<mean(phlog)<<" acid="<<acid<<" base="<<base<<"\n";
    }
}
int main(){ ph_033::control(); return 0; }
