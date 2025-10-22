// Context: Agricultural drone fertilization nozzle map

#include <iostream>
int main(){
    float flowA=0.2F;     // C
    float flowB=0.2F;     // C
    unsigned cells=0U;    // C
    unsigned faults=0U;   // C
    double scale=1.0;     // C
    double bias=0.0;      // C
    scale+=0.05; flowA+=0.01F;
    std::cout<<flowA<<","<<flowB<<","<<cells<<","<<faults<<","<<scale<<","<<bias<<"\n";
    return 0;
}
