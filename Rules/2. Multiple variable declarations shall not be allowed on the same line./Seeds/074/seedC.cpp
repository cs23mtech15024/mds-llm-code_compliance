// Context: Weather balloon telemetry decoder

#include <iostream>
int main(){
    double altitude=0.0;       // C
    double temp=0.0;           // C
    float humidity=0.0F;       // C
    float pressure=1013.0F;    // C
    unsigned packets=0U;       // C
    unsigned lost=0U;          // C
    altitude += 10.0; packets++;
    std::cout<<altitude<<","<<temp<<","<<humidity<<","<<pressure<<","<<packets<<","<<lost<<"\n";
    return 0;
}
