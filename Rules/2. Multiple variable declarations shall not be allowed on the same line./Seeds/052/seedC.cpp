// Context: Electric bus regenerative braking controller

#include <iostream>
int main(){
    float speed=12.0F;     // C
    float decel=0.0F;      // C
    double soc=0.65;       // C
    double limit=0.90;     // C
    int events=0;          // C
    int cutouts=0;         // C
    decel += 0.5F; soc += 0.01;
    std::cout<<speed<<","<<decel<<","<<soc<<","<<limit<<","<<events<<","<<cutouts<<"\n";
    return 0;
}
