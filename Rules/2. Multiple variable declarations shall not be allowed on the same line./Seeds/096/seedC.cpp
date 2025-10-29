// Context: Chocolate tempering machine controller

#include <iostream>
int main(){
    float temp=31.5F;          // C
    float target=32.0F;        // C
    double viscosity=0.0;      // C
    double crystals=0.0;       // C
    int cycles=0;              // C
    int batches=0;             // C
    temp += 0.1F; cycles++;
    std::cout<<temp<<","<<target<<","<<viscosity<<","<<crystals<<","<<cycles<<","<<batches<<"\n";
    return 0;
}
