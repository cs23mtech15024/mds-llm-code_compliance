// Context: Hospital negative-pressure room monitor

// ------ Non-Compliant Program (036_nc.cpp)
// Intentionally groups declarators; violates 8-0-1.
#include <iostream>
#include <iomanip>
namespace iso_036 {
    struct Press { double pa; double target; }; // OK
    void run(){
        double pa=-5.0, target=-8.0;           // NC
        float flow=0.0F, leak=0.0F;            // NC
        int alarms=0, warns=0;                 // NC
        Press p{pa,target};
        for (unsigned i=0U;i<10U;++i){
            flow += 0.2F; p.pa -= 0.3; if (p.pa>-6.0){ alarms++; }
            if (flow>1.5F){ warns++; }
            if ((i%3U)==0U){ std::cout<<"i="<<i<<" pa="<<p.pa<<" flow="<<flow<<"\n"; }
        }
        std::cout<<"A="<<alarms<<" W="<<warns<<"\n";
    }
}
int main(){ iso_036::run(); return 0; }
