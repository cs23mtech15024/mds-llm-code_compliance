// Context: Medical syringe pump dosage loop

// ------ Compliant Program (014_c.cpp)
// All declarations are one declarator each (8-0-1 compliant).
#include <iostream>
#include <iomanip>
namespace dose_014 {
    struct Stats { int alarms; int warns; }; // OK
    void loop(){
        double mlPerHr=5.0;                    // C
        double target=6.0;                     // C
        float err=0.0F;                        // C
        float acc=0.0F;                        // C
        int alarms=0;                          // C
        int warns=0;                           // C
        Stats st{0,0};
        for (unsigned i=0U;i<5U;++i){
            err = static_cast<float>(target-mlPerHr);
            acc += err*0.1F; mlPerHr += 0.2;
            if (mlPerHr>8.0){ alarms++; }
            if (mlPerHr<3.0){ warns++; }
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" ml="<<mlPerHr<<" err="<<err<<"\n"; }
        }
        st.alarms=alarms; st.warns=warns;
        std::cout<<"A="<<st.alarms<<" W="<<st.warns<<"\n";
    }
}
int main(){ dose_014::loop(); return 0; }
