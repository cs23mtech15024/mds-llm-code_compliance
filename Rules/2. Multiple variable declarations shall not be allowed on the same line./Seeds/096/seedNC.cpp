// Context: Chocolate tempering machine controller

#include <iostream>
int main(){
    float temp=31.5F, target=32.0F;       // NC
    double viscosity=0.0, crystals=0.0;   // NC
    int cycles=0, batches=0;              // NC
    temp += 0.1F; cycles++;
    std::cout<<temp<<","<<target<<","<<viscosity<<","<<crystals<<","<<cycles<<","<<batches<<"\n";
    return 0;
}
