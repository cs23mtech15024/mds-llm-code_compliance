// Context: Volcano monitoring seismic trigger filter

#include <iostream>
int main(){
    double a=0.0;         // C
    double b=0.0;         // C
    float thr=0.7F;       // C
    float env=0.0F;       // C
    int hits=0;           // C
    int alerts=0;         // C
    a += 0.2; b += 0.3; env += 0.05F; if(a+b>1.0){ hits++; }
    std::cout<<a<<","<<b<<","<<thr<<","<<env<<","<<hits<<","<<alerts<<"\n";
    return 0;
}
