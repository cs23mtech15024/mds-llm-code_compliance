// Context: Drone swarm perimeter sentry ring

#include <iostream>
int main(){
    float r=50.0F, ang=0.0F;         // NC
    float v=2.0F, turn=0.0F;         // NC
    unsigned drones=6U, flags=0U;    // NC
    ang += 0.2F; r += 0.5F;
    std::cout<<r<<","<<ang<<","<<v<<","<<turn<<","<<drones<<","<<flags<<"\n";
    return 0;
}
