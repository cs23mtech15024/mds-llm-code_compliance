// Context: Deep-sea ROV buoyancy trim controller

#include <iostream>
int main(){
    double depth=50.0, tgt=47.5;   // NC
    float pump=0.0F, bleed=0.0F;   // NC
    unsigned steps=0U, trips=0U;   // NC
    pump += 0.2F; depth -= 0.5;
    std::cout<<depth<<","<<tgt<<","<<pump<<","<<bleed<<","<<steps<<","<<trips<<"\n";
    return 0;
}
