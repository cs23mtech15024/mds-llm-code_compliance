// Context: EV charging bay scheduler

// ------ Compliant Program (005_c.cpp)
// Split every declaration to one declarator to satisfy 8-0-1.
#include <iostream>
#include <vector>
#include <algorithm>
namespace ev_005 {
    struct Bay { int id; double kW; }; // OK
    static double sum(const std::vector<Bay>& v){ 
        double t=0.0; 
        for (std::size_t i=0; i<v.size(); ++i){ 
            t+=v[i].kW; 
        } 
        return t; 
    }
    void schedule(){
        int active=2;                 // C
        int queued=3;                 // C
        double pwrA=7.2;              // C
        double pwrB=7.2;              // C
        bool peak=false;              // C
        bool shed=false;              // C
        std::vector<Bay> bays{{1,7.2},{2,7.2}};
        double total=pwrA+pwrB;
        if (peak){ shed=true; total*=0.8; }
        std::cout<<"active="<<active<<" queued="<<queued<<" total="<<total
                 <<" fleet="<<sum(bays)<<" shed="<<shed<<"\n";
    }
}
int main(){ ev_005::schedule(); return 0; }