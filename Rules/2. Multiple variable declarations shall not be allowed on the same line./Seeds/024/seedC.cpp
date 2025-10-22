// Context: Drone geofencing boundary check

#include <iostream>
int main(){
    double lat=0.0;      // C
    double lon=0.0;      // C
    float r=100.0F;      // C
    float d=0.0F;        // C
    int breaches=0;      // C
    int warns=0;         // C
    d = 50.0F; lat += 0.001; lon -= 0.001;
    std::cout<<lat<<","<<lon<<","<<r<<","<<d<<","<<breaches<<","<<warns<<"\n";
    return 0;
}
