// Context: Bioreactor pH stabilizer

#include <iostream>
int main(){
    double pH=7.0, temp=37.0;             // NC
    float dissolvedO2=80.0F, agitation=200.0F; // NC
    unsigned samples=0U, adjustments=0U;  // NC
    pH += 0.01; samples++;
    std::cout<<pH<<","<<temp<<","<<dissolvedO2<<","<<agitation<<","<<samples<<","<<adjustments<<"\n";
    return 0;
}
