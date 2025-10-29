// Context: Weather balloon telemetry decoder

#include <iostream>
int main(){
    double altitude=0.0, temp=0.0;        // NC
    float humidity=0.0F, pressure=1013.0F; // NC
    unsigned packets=0U, lost=0U;         // NC
    altitude += 10.0; packets++;
    std::cout<<altitude<<","<<temp<<","<<humidity<<","<<pressure<<","<<packets<<","<<lost<<"\n";
    return 0;
}
