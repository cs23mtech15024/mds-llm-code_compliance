// Context: Aquarium life support system controller

#include <iostream>
int main(){
    float temp=26.0F;          // C
    float pH=8.2F;             // C
    double salinity=1.025;     // C
    double alkalinity=8.0;     // C
    unsigned pumps=3U;         // C
    unsigned heaters=2U;       // C
    temp += 0.1F; pumps++;
    std::cout<<temp<<","<<pH<<","<<salinity<<","<<alkalinity<<","<<pumps<<","<<heaters<<"\n";
    return 0;
}
