// Context: Smart grid frequency droop emulator

// ------ Non-Compliant Program (069_nc.cpp)
// Groups declarators (// NC); violates MISRA C++ 8-0-1.
#include <iostream>
#include <vector>
#include <numeric>
namespace droop_069 {
    struct Grid { double f; double p; }; // OK
    double mean(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void emulate(){
        double f=50.0, set=50.0;                // NC
        float droop=0.05F, p=0.0F;              // NC
        int steps=0, trips=0;                   // NC
        std::vector<double> dist{-0.3,0.1,-0.2,0.0,0.2,0.3};
        for (std::size_t i=0;i<dist.size();++i){
            f = set + dist[i];
            p += static_cast<float>((set - f)*static_cast<double>(droop)*20.0);
            if (std::fabs(set - f)>0.25){ trips++; }
            steps++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" f="<<f<<" p="<<p<<"\n"; }
        }
        std::cout<<"steps="<<steps<<" trips="<<trips<<" p_mean="<<mean(dist)<<"\n";
    }
}
int main(){ droop_069::emulate(); return 0; }
