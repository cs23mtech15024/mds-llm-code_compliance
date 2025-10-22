// Context: Smart greenhouse CO2 enrichment loop

// ------ Non-Compliant Program (064_nc.cpp)
// Demonstrates 8-0-1 violation via grouped declarators.
#include <iostream>
#include <vector>
#include <numeric>
namespace co2_064 {
    struct Env { double ppm; double set; }; // OK
    static double clampd(double v,double lo,double hi){ return v<lo?lo:(v>hi?hi:v); }
    void enrich(){
        double ppm=420.0, set=800.0;            // NC
        float valve=0.0F, leak=0.0F;            // NC
        unsigned ticks=0U, alarms=0U;           // NC
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
