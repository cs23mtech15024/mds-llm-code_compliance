// Context: Agricultural drone fertilization nozzle map

#include <iostream>
int main(){
    float flowA=0.2F, flowB=0.2F;    // NC
    unsigned cells=0U, faults=0U;    // NC
    double scale=1.0, bias=0.0;      // NC
    scale+=0.05; flowA+=0.01F;
    std::cout<<flowA<<","<<flowB<<","<<cells<<","<<faults<<","<<scale<<","<<bias<<"\n";
    return 0;
}
