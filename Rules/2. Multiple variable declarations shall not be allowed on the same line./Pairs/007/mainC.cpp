// Context: Smart thermostat adaptive PID

// ------ Compliant Program (007_c.cpp)
// 8-0-1 compliant rewrite.
#include <iostream>
#include <cmath>
#include <algorithm>
namespace pid_007 {
    struct Gains { double kp; double ki; double kd; }; // OK
    static double sat(double u){ return std::max(-100.0, std::min(100.0,u)); }
    void control(){
        double kp=1.0;                 // C
        double ki=0.1;                 // C
        double kd=0.01;                // C
        float target=22.0F;            // C
        float room=21.5F;              // C
        bool heat=true;                // C
        bool cool=false;               // C
        double e = static_cast<double>(target-room);
        double u = kp*e + ki*e + kd*0.0;
        u = sat(u);
        if (u>0.0){ heat=true; cool=false; }
        else { heat=false; cool=true; }
        std::cout<<"e="<<e<<" u="<<u<<" heat="<<heat<<" cool="<<cool<<"\n";
    }
}
int main(){ pid_007::control(); return 0; }
