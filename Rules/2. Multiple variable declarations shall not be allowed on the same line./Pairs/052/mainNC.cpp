// Context: Electric bus regenerative braking controller

// ------ Non-Compliant Program (052_nc.cpp)
// Multiple declarators in a declaration -> violation of MISRA C++ 8-0-1.
#include <iostream>
#include <vector>
#include <cmath>
namespace ebus_052 {
    struct State { float v; float dec; }; // OK
    static float clip(float v,float lo,float hi){ return std::max(lo,std::min(hi,v)); }
    void loop(){
        float speed=12.0F, decel=0.0F;         // NC
        double soc=0.65, limit=0.90;           // NC
        int events=0, cutouts=0;               // NC
        State s{speed,decel};
        for (int k=0;k<14;++k){
            float req = (k%2==0)?0.6F:0.2F;
            float u = clip(req - s.dec, -0.5F, 0.5F);
            s.dec += u; s.v = clip(s.v - s.dec, 0.0F, 25.0F);
            soc += (s.dec>0.4F)?0.002:0.0005; if (soc>limit){ cutouts++; s.dec=0.0F; }
            events++;
            if ((k%2)==0){ std::cout<<"k="<<k<<" v="<<s.v<<" dec="<<s.dec<<" soc="<<soc<<"\n"; }
        }
        std::cout<<"events="<<events<<" cutouts="<<cutouts<<"\n";
    }
}
int main(){ ebus_052::loop(); return 0; }
