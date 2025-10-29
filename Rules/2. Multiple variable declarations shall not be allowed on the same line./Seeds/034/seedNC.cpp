// Context: Electric bus regenerative braking controller

#include <iostream>
int main(){
    float speed=12.0F, decel=0.0F;   // NC
    double soc=0.65, limit=0.90;     // NC
    int events=0, cutouts=0;         // NC
    decel += 0.5F; soc += 0.01;
    std::cout<<speed<<","<<decel<<","<<soc<<","<<limit<<","<<events<<","<<cutouts<<"\n";
    return 0;
}
