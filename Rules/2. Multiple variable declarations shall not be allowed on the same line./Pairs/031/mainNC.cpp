// Context: Hydroelectric turbine governor loop

// ------ Non-Compliant Program (031_nc.cpp)
// Rule: MISRA C++ 8-0-1 — a declaration shall contain no more than one declarator.
// This file intentionally violates 8-0-1 via grouped declarators (// NC).
#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
namespace hydro_031 {
    struct GovState { double rpm; double valve; }; // OK: members are distinct
    static double clamp(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    void govern(){
        double rpm=300.0, set=310.0;            // NC
        float kp=0.9F, ki=0.03F;                // NC
        unsigned steps=0U, faults=0U;           // NC
        GovState s{rpm, 0.0};
        const double dt=0.2;
        std::array<double,10U> refs{312,309,308,310,311,309,307,309,310,310};
        for (std::size_t i=0U;i<refs.size();++i){
            set = refs[i];
            double err = set - s.rpm;
            static double integ=0.0; integ += err*dt;
            double u = static_cast<double>(kp)*err + static_cast<double>(ki)*integ;
            u = clamp(u,-5.0,5.0);
            s.valve = u; s.rpm += s.valve*0.8; steps++;
            if (std::fabs(err)>20.0){ faults++; }
            if ((i%2U)==0U){
                std::cout<<"i="<<i<<" rpm="<<std::fixed<<std::setprecision(1)<<s.rpm
                         <<" sp="<<set<<" v="<<s.valve<<"\n";
            }
        }
        std::cout<<"steps="<<steps<<" faults="<<faults<<"\n";
    }
}
int main(){ hydro_031::govern(); return 0; }
