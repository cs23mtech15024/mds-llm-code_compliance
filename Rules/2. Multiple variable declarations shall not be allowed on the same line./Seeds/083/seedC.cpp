// Context: Deep-sea ROV buoyancy trim controller

#include <iostream>
int main(){
    double depth=50.0;    // C
    double tgt=47.5;      // C
    float pump=0.0F;      // C
    float bleed=0.0F;     // C
    unsigned steps=0U;    // C
    unsigned trips=0U;    // C
    pump += 0.2F; depth -= 0.5;
    std::cout<<depth<<","<<tgt<<","<<pump<<","<<bleed<<","<<steps<<","<<trips<<"\n";
    return 0;
}
