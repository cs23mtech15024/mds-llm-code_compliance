// Context: Hydroelectric turbine governor loop

// ------ Compliant Program (031_c.cpp)
// Fix: each declaration has a single declarator (8-0-1 compliant).
#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
namespace hydro_031 {
    struct GovState { double rpm; double valve; }; // OK
    static double clamp(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    void govern(){
        double rpm=300.0;                         // C
        double set=310.0;                         // C
        float kp=0.9F;                            // C
        float ki=0.03F;                           // C
        unsigned steps=0U;                        // C
        unsigned faults=0U;                       // C
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
