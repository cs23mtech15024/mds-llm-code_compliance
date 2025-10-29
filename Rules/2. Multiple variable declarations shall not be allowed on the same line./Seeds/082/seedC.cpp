// Context: Bioreactor pH stabilizer

#include <iostream>
int main(){
    double pH=7.0;             // C
    double temp=37.0;          // C
    float dissolvedO2=80.0F;   // C
    float agitation=200.0F;    // C
    unsigned samples=0U;       // C
    unsigned adjustments=0U;   // C
    pH += 0.01; samples++;
    std::cout<<pH<<","<<temp<<","<<dissolvedO2<<","<<agitation<<","<<samples<<","<<adjustments<<"\n";
    return 0;
}
