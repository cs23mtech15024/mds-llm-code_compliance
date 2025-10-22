// Context: Power substation thermal monitor

#include <iostream>
int main(){
    double tCab=36.5;      // C
    double tBus=38.0;      // C
    float rmsA=100.0F;     // C
    float rmsB=98.5F;      // C
    bool fan=false;        // C
    bool alert=false;      // C
    alert = (tBus>40.0);
    std::cout<<tCab<<","<<tBus<<","<<rmsA<<","<<rmsB<<","<<fan<<","<<alert<<"\n";
    return 0;
}
