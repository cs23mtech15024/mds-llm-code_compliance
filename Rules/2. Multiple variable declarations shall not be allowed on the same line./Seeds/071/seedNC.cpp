// Context: Laser cutting path optimizer

#include <iostream>
int main(){
    float posX=0.0F, posY=0.0F;       // NC
    float power=100.0F, speed=50.0F;  // NC
    int cuts=0, errors=0;             // NC
    posX += 1.0F; cuts++;
    std::cout<<posX<<","<<posY<<","<<power<<","<<speed<<","<<cuts<<","<<errors<<"\n";
    return 0;
}
