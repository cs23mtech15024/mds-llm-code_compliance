// Context: Tidal energy converter inverter control

// ------ Non-Compliant Program (041_nc.cpp)
// Rule: MISRA C++ 8-0-1 — each declaration must have no more than one declarator.
// This file intentionally groups declarators (// NC) to illustrate violations.
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
namespace tidal_041 {
    struct Phase { double vdc; double vac; }; // OK: members are separate
    static double clamp(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    static double rms(const std::vector<double>& a){ double s=0.0; for(double x:a){ s+=x*x; } return (a.empty()?0.0:std::sqrt(s/a.size())); }
    void control(){
        double vdc=700.0, vac=0.0;             // NC
        float kp=0.8F, ki=0.03F;               // NC
        unsigned cycles=0U, trips=0U;          // NC
        Phase p{vdc,vac};
        std::vector<double> vhist;
        for (unsigned i=0U;i<12U;++i){
            double err = 650.0 - p.vdc;
            static double integ=0.0; integ += err*0.01;
            double u = static_cast<double>(kp)*err + static_cast<double>(ki)*integ;
            u = clamp(u,-20.0,20.0);
            p.vac = clamp(p.vac + u*0.5, 0.0, 400.0);
            p.vdc = clamp(p.vdc - 0.8*u, 500.0, 800.0);
            vhist.push_back(p.vac); cycles++;
            if (std::fabs(err)>80.0){ trips++; }
            if ((i%2U)==0U){
                std::cout<<"i="<<i<<" vdc="<<std::fixed<<std::setprecision(1)<<p.vdc
                         <<" vac="<<p.vac<<" u="<<u<<"\n";
            }
        }
        std::cout<<"cycles="<<cycles<<" trips="<<trips<<" vac_rms="<<rms(vhist)<<"\n";
    }
}
int main(){ tidal_041::control(); return 0; }
