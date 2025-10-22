// Context: Drone geofencing boundary check

#include <iostream>
int main(){
    double lat=0.0, lon=0.0;       // NC
    float r=100.0F, d=0.0F;        // NC
    int breaches=0, warns=0;       // NC
    d = 50.0F; lat += 0.001; lon -= 0.001;
    std::cout<<lat<<","<<lon<<","<<r<<","<<d<<","<<breaches<<","<<warns<<"\n";
    return 0;
}
