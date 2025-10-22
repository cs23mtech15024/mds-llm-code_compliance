// Context: Automated dairy vacuum regulator

// ------ Compliant Program (054_c.cpp)
// One declarator per declaration; identical control logic.
#include <iostream>
#include <vector>
namespace dairy_054 {
    struct Vac { double kPa; double trim; }; // OK
    void regulate(){
        double vac=45.0;                        // C
        double target=50.0;                     // C
        float leak=0.0F;                        // C
        float trim=0.0F;                        // C
        int alarms=0;                            // C
        int resets=0;                            // C
        Vac v{vac,0.0};
        for (int i=0;i<15;++i){
            double e = target - v.kPa;
            trim += static_cast<float>(e*0.02);
            v.kPa += e*0.2 - static_cast<double>(leak);
            if (v.kPa>55.0){ alarms++; }
            if ((i%5)==0){ resets++; leak += 0.1F; }
            if ((i%3)==0){ std::cout<<"i="<<i<<" kPa="<<v.kPa<<" trim="<<trim<<"\n"; }
        }
        std::cout<<"A="<<alarms<<" R="<<resets<<"\n";
    }
}
int main(){ dairy_054::regulate(); return 0; }
