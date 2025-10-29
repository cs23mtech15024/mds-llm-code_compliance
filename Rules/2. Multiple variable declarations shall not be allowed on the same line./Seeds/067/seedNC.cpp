// Context: Particle accelerator beam position monitor

#include <iostream>
int main(){
    float posX=0.0F, posY=0.0F;       // NC
    double energy=1.5, intensity=0.0; // NC
    int shots=0, trips=0;             // NC
    posX += 0.01F; shots++;
    std::cout<<posX<<","<<posY<<","<<energy<<","<<intensity<<","<<shots<<","<<trips<<"\n";
    return 0;
}
