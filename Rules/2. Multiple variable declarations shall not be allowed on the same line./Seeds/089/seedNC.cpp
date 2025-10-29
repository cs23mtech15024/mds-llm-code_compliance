// Context: Aquarium life support system controller

#include <iostream>
int main(){
    float temp=26.0F, pH=8.2F;            // NC
    double salinity=1.025, alkalinity=8.0; // NC
    unsigned pumps=3U, heaters=2U;        // NC
    temp += 0.1F; pumps++;
    std::cout<<temp<<","<<pH<<","<<salinity<<","<<alkalinity<<","<<pumps<<","<<heaters<<"\n";
    return 0;
}
