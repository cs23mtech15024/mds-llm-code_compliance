// Context: Smart thermostat adaptive PID

// ------ Non-Compliant Program (007_nc.cpp)
// Intentionally violates 8-0-1 via multiple declarators per declaration.
#include <iostream>
#include <cmath>
#include <algorithm>
namespace pid_007 {
    struct Gains { double kp; double ki; double kd; }; // OK
    static double sat(double u){ return std::max(-100.0, std::min(100.0,u)); }
    void control(){
        double kp=1.0, ki=0.1, kd=0.01;   // NC
        float target=22.0F, room=21.5F;   // NC
        bool heat=true, cool=false;       // NC
        double e = static_cast<double>(target-room);
        double u = kp*e + ki*e + kd*0.0;
        u = sat(u);
        if (u>0.0){ heat=true; cool=false; }
        else { heat=false; cool=true; }
        std::cout<<"e="<<e<<" u="<<u<<" heat="<<heat<<" cool="<<cool<<"\n";
    }
}
int main(){ pid_007::control(); return 0; }
