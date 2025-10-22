// Context: Smart grid feeder balancing

// ------ Non-Compliant Program (015_nc.cpp)
// Intentional grouping of declarators breaks 8-0-1.
#include <iostream>
#include <vector>
#include <numeric>
namespace grid_015 {
    struct Phase { double v; }; // OK
    static double sum(const std::vector<Phase>& p){ return std::accumulate(p.begin(),p.end(),0.0,[](double a,const Phase& b){return a+b.v;}); }
    void balance(){
        double phaseA=230.0, phaseB=231.0;      // NC
        double phaseC=229.5, total=0.0;         // NC
        int taps=0, changes=0;                  // NC
        std::vector<Phase> ph{{230.0},{231.0},{229.5}};
        total = phaseA+phaseB+phaseC;
        if (total/3.0>230.5){ taps++; changes++; }
        std::cout<<"avg="<<(total/3.0)<<" taps="<<taps<<" chg="<<changes<<" sum="<<sum(ph)<<"\n";
    }
}
int main(){ grid_015::balance(); return 0; }
