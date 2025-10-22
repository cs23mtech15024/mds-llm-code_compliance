// Context: Medical ventilator flow estimator

// ------ Compliant Program (003_c.cpp)
// Compliant rewrite: one declarator per declaration.
#include <iostream>
#include <vector>
#include <numeric>
namespace med_003 {
    struct Sample { double flow; double pressure; }; // OK
    static double avg(const std::vector<double>& v){ return v.empty()?0.0:std::accumulate(v.begin(),v.end(),0.0)/static_cast<double>(v.size()); }
    void estimate(){
        double flow=0.0;                 // C
        double pressure=0.0;             // C
        long alarms=0L;                  // C
        long warnings=0L;                // C
        bool humidOn=false;              // C
        bool heaterOn=false;             // C
        std::vector<double> buf{0.4,0.5,0.6,0.55,0.52};
        flow = avg(buf);
        if (flow>1.5){ alarms++; }
        if (pressure<0.0){ warnings++; }
        std::cout<<"flow="<<flow<<" p="<<pressure<<" a="<<alarms<<" w="<<warnings
                 <<" humid="<<humidOn<<" heat="<<heaterOn<<"\n";
    }
}
int main(){ med_003::estimate(); return 0; }
