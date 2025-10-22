// Context: Lunar habitat airlock pressure equalizer

// ------ Non-Compliant Program (070_nc.cpp)
// Multiple declarators per declaration (// NC) — violates 8-0-1.
#include <iostream>
#include <array>
#include <algorithm>
namespace air_070 {
    struct Lock { double cabin; double lock; }; // OK
    static double clampd(double v,double lo,double hi){ return std::max(lo,std::min(hi,v)); }
    void equalize(){
        double cabin=55.0, lock=10.0;            // NC
        float valve=0.0F, leak=0.0F;             // NC
        unsigned t=0U, alarms=0U;                // NC
        std::array<double,6U> leaks{0.0,0.0,0.1,0.0,0.2,0.0};
        for (std::size_t i=0;i<leaks.size();++i){
            valve = std::min(1.0F,valve + 0.1F);
            double flow = static_cast<double>(valve)*2.0 - static_cast<double>(leak);
            lock = clampd(lock + flow, 0.0, cabin);
            leak = static_cast<float>(leaks[i]);
            if (cabin-lock<1.0){ alarms++; }
            t++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" lock="<<lock<<" valve="<<valve<<"\n"; }
        }
        std::cout<<"t="<<t<<" alarms="<<alarms<<"\n";
    }
}
int main(){ air_070::equalize(); return 0; }
