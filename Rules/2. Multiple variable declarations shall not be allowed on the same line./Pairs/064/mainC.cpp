// Context: Smart greenhouse CO2 enrichment loop

// ------ Compliant Program (064_c.cpp)
// Compliant: one declarator per declaration.
#include <iostream>
#include <vector>
#include <numeric>
namespace co2_064 {
    struct Env { double ppm; double set; }; // OK
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    void enrich(){
        double ppm=420.0;                         // C
        double set=800.0;                         // C
        float valve=0.0F;                         // C
        float leak=0.0F;                          // C
        unsigned ticks=0U;                        // C
        unsigned alarms=0U;                       // C
        std::vector<double> sun{0.2,0.6,0.9,0.5,0.3};
        for (std::size_t i=0;i<sun.size();++i){
            double err = set - ppm; valve = static_cast<float>(clampd(valve + 0.001*err, 0.0, 1.0));
            ppm = clampd(ppm + 5.0 + static_cast<double>(valve)*15.0 - static_cast<double>(leak)*10.0, 300.0, 2000.0);
            if (ppm>1200.0){ alarms++; }
            ticks++;
            if ((i%2U)==0U){ std::cout<<"i="<<i<<" ppm="<<ppm<<" valve="<<valve<<"\n"; }
        }
        std::cout<<"ticks="<<ticks<<" alarms="<<alarms<<"\n";
    }
}
int main(){ co2_064::enrich(); return 0; }
