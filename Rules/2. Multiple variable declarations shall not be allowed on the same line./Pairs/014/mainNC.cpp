// Context: Medical syringe pump dosage loop

// ------ Non-Compliant Program (014_nc.cpp)
// 8-0-1 violations included for demonstration.
#include <iostream>
#include <iomanip>
namespace dose_014 {
    struct Stats { int alarms; int warns; }; // OK
    void loop(){
        double mlPerHr=5.0, target=6.0;        // NC
        float err=0.0F, acc=0.0F;              // NC
        int alarms=0, warns=0;                 // NC
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
