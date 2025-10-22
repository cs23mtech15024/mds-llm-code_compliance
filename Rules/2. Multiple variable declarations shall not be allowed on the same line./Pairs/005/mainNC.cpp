// Context: EV charging bay scheduler

// ------ Non-Compliant Program (005_nc.cpp)
// Demonstrates 8-0-1 violations with multiple declarators.
#include <iostream>
#include <vector>
#include <algorithm>
namespace ev_005 {
    struct Bay { int id; double kW; }; // OK
    static double sum(const std::vector<Bay>& v){ double t=0.0; for (const auto& b:v){ t+=b.kW; } return t; }
    void schedule(){
        int active=2, queued=3;            // NC
        double pwrA=7.2, pwrB=7.2;         // NC
        bool peak=false, shed=false;       // NC
        std::vector<Bay> bays{{1,7.2},{2,7.2}};
        double total=pwrA+pwrB;
        if (peak){ shed=true; total*=0.8; }
        std::cout<<"active="<<active<<" queued="<<queued<<" total="<<total
                 <<" fleet="<<sum(bays)<<" shed="<<shed<<"\n";
    }
}
int main(){ ev_005::schedule(); return 0; }
