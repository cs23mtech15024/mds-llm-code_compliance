// Context: Coal plant boiler feedwater control

// ------ Compliant Program (037_c.cpp)
// One declarator per declaration.
#include <iostream>
#include <vector>
namespace boiler_037 {
    struct Valve { double pos; double cmd; }; // OK
    void loop(){
        double lvl=50.0;                         // C
        double sp=55.0;                          // C
        float kp=1.1F;                           // C
        float ki=0.04F;                          // C
        int opens=0;                              // C
        int closes=0;                             // C
        Valve v{0.0,0.0};
        for (int i=0;i<12;++i){
            double e = sp - lvl;
            v.cmd = kp*e + ki*e;
            v.pos += v.cmd*0.01; lvl += v.pos*0.05;
            if (v.pos>1.0){ opens++; }
            if (v.pos<-1.0){ closes++; }
            if ((i%3)==0){ std::cout<<"i="<<i<<" lvl="<<lvl<<" pos="<<v.pos<<"\n"; }
        }
        std::cout<<"open="<<opens<<" close="<<closes<<"\n";
    }
}
int main(){ boiler_037::loop(); return 0; }
