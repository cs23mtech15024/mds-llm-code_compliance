// Context: Smart hydroponics nutrient dosing mixer

#include <iostream>
int main(){
    double ec=1.5;        // C
    double target=1.8;    // C
    float aDose=0.0F;     // C
    float bDose=0.0F;     // C
    unsigned cycles=0U;   // C
    unsigned alarms=0U;   // C
    ec += 0.05; aDose += 0.01F;
    std::cout<<ec<<","<<target<<","<<aDose<<","<<bDose<<","<<cycles<<","<<alarms<<"\n";
    return 0;
}
