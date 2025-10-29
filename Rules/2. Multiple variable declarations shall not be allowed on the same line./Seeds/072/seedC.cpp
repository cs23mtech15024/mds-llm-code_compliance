// Context: Desalination plant membrane pressure controller

#include <iostream>
int main(){
    double inPressure=5.5;  // C
    double outPressure=1.0; // C
    float flow=500.0F;      // C
    float salinity=35.0F;   // C
    unsigned hours=0U;      // C
    unsigned cleanings=0U;  // C
    flow += 1.0F; hours++;
    std::cout<<inPressure<<","<<outPressure<<","<<flow<<","<<salinity<<","<<hours<<","<<cleanings<<"\n";
    return 0;
}
