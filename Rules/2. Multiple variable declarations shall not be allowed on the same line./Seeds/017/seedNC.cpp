// Context: Power substation thermal monitor

#include <iostream>
int main(){
    double tCab=36.5, tBus=38.0;      // NC
    float rmsA=100.0F, rmsB=98.5F;    // NC
    bool fan=false, alert=false;      // NC
    alert = (tBus>40.0);
    std::cout<<tCab<<","<<tBus<<","<<rmsA<<","<<rmsB<<","<<fan<<","<<alert<<"\n";
    return 0;
}
