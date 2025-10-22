// Context: Maritime autopilot heading hold

// ------ Compliant Program (011_c.cpp)
// Fix: split every declaration into one declarator to satisfy 8-0-1.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>
namespace ship_011 {
    struct State { double hdg; double rate; }; // OK
    static double clamp(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    void run(){
        double heading=0.0;                       // C
        double setpoint=90.0;                     // C
        float kp=1.2F;                            // C
        float ki=0.02F;                           // C
        int ticks=0;                              // C
        int faults=0;                             // C
        State s{0.0,0.0};
        const double dt=0.1;
        std::array<double,8U> refs{85,88,90,92,90,89,91,90};
        for (std::size_t i=0U;i<refs.size();++i){
            setpoint = refs[i];
            double err = setpoint - s.hdg;
            static double integ=0.0; integ += err*dt;
            double u = static_cast<double>(kp)*err + static_cast<double>(ki)*integ;
            u = clamp(u,-10.0,10.0);
            s.rate = u; s.hdg += s.rate*dt; ticks++;
            if (std::fabs(err)>20.0){ faults++; }
            if ((i%2U)==0U){
                std::cout<<"i="<<i<<" hdg="<<std::fixed<<std::setprecision(1)<<s.hdg
                         <<" sp="<<setpoint<<" u="<<u<<"\n";
            }
        }
        std::cout<<"ticks="<<ticks<<" faults="<<faults<<"\n";
    }
}
int main(){ ship_011::run(); return 0; }
