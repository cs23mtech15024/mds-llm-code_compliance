// Context: Particle accelerator beam position monitor

#include <iostream>
int main(){
    float posX=0.0F;       // C
    float posY=0.0F;       // C
    double energy=1.5;     // C
    double intensity=0.0;  // C
    int shots=0;           // C
    int trips=0;           // C
    posX += 0.01F; shots++;
    std::cout<<posX<<","<<posY<<","<<energy<<","<<intensity<<","<<shots<<","<<trips<<"\n";
    return 0;
}
