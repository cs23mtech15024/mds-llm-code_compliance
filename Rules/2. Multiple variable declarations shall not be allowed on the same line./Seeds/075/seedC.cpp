// Context: Drone swarm perimeter sentry ring

#include <iostream>
int main(){
    float r=50.0F;        // C
    float ang=0.0F;       // C
    float v=2.0F;         // C
    float turn=0.0F;      // C
    unsigned drones=6U;   // C
    unsigned flags=0U;    // C
    ang += 0.2F; r += 0.5F;
    std::cout<<r<<","<<ang<<","<<v<<","<<turn<<","<<drones<<","<<flags<<"\n";
    return 0;
}
