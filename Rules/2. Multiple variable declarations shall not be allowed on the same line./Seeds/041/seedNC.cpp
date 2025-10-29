// Context: Volcano monitoring seismic trigger filter

#include <iostream>
int main(){
    double a=0.0, b=0.0;             // NC
    float thr=0.7F, env=0.0F;        // NC
    int hits=0, alerts=0;            // NC
    a += 0.2; b += 0.3;
    env += 0.05F; if(a+b>1.0){ hits++; }
    std::cout<<a<<","<<b<<","<<thr<<","<<env<<","<<hits<<","<<alerts<<"\n";
    return 0;
}
