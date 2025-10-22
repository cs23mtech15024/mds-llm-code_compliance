// Context: 3D printer thermal safety loop

// ------ Compliant Program (026_c.cpp)
// One declarator per declaration; same logic retained.
#include <iostream>
#include <iomanip>
namespace print_026 {
    struct Temps { double bed; double noz; }; // OK
    void run(){
        double bed=50.0;                       // C
        double nozzle=200.0;                    // C
        double target=210.0;                    // C
        double ramp=0.0;                        // C
        int alarms=0;                            // C
        int warns=0;                             // C
        Temps t{bed,nozzle};
        for (int i=0;i<8;++i){
            ramp = target - t.noz; t.noz += 5.0; if (t.noz>230.0){ alarms++; }
            if (t.bed<40.0){ warns++; }
            if ((i%2)==0){ std::cout<<"i="<<i<<" noz="<<t.noz<<" ramp="<<ramp<<"\n"; }
        }
        std::cout<<"A="<<alarms<<" W="<<warns<<"\n";
    }
}
int main(){ print_026::run(); return 0; }
