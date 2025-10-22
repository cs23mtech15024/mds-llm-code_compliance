// Context: Smart hydroponics nutrient dosing mixer

#include <iostream>
int main(){
    double ec=1.5, target=1.8;       // NC
    float aDose=0.0F, bDose=0.0F;    // NC
    unsigned cycles=0U, alarms=0U;   // NC
    ec += 0.05; aDose += 0.01F;
    std::cout<<ec<<","<<target<<","<<aDose<<","<<bDose<<","<<cycles<<","<<alarms<<"\n";
    return 0;
}
