// Context: Drone geofencing boundary check

// ------ Compliant Program (024_c.cpp)
// Compliant: single declarator per declaration.
#include <iostream>
#include <vector>
namespace fence_024 {
    struct Geo { double lat; double lon; }; // OK
    static double h(double a,double b){ return (a*a+b*b); }
    void check(){
        double lat=0.0;                          // C
        double lon=0.0;                          // C
        float r=100.0F;                          // C
        float d=0.0F;                            // C
        int breaches=0;                           // C
        int warns=0;                              // C
        std::vector<Geo> path{{0.0,0.0},{0.001,-0.001},{0.002,-0.002}};
        for (std::size_t i=0U;i<path.size();++i){ lat=path[i].lat; lon=path[i].lon; d = 50.0F; if (h(lat,lon)>0.00001){ warns++; }
            if ((i%1U)==0U){ std::cout<<"i="<<i<<" lat="<<lat<<" lon="<<lon<<" d="<<d<<"\n"; }
        }
        std::cout<<"breaches="<<breaches<<" warns="<<warns<<"\n";
    }
}
int main(){ fence_024::check(); return 0; }
