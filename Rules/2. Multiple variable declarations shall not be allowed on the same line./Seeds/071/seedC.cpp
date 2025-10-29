// Context: Laser cutting path optimizer

#include <iostream>
int main(){
    float posX=0.0F;       // C
    float posY=0.0F;       // C
    float power=100.0F;    // C
    float speed=50.0F;     // C
    int cuts=0;            // C
    int errors=0;          // C
    posX += 1.0F; cuts++;
    std::cout<<posX<<","<<posY<<","<<power<<","<<speed<<","<<cuts<<","<<errors<<"\n";
    return 0;
}
