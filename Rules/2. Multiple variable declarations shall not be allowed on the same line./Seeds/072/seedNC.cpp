// Context: Desalination plant membrane pressure controller

#include <iostream>
int main(){
    double inPressure=5.5, outPressure=1.0; // NC
    float flow=500.0F, salinity=35.0F;      // NC
    unsigned hours=0U, cleanings=0U;        // NC
    flow += 1.0F; hours++;
    std::cout<<inPressure<<","<<outPressure<<","<<flow<<","<<salinity<<","<<hours<<","<<cleanings<<"\n";
    return 0;
}
