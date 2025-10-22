// Context: Lunar habitat airlock pressure equalizer

#include <iostream>
int main(){
    double cabin=55.0, lock=10.0;    // NC
    float valve=0.0F, leak=0.0F;     // NC
    unsigned t=0U, alarms=0U;        // NC
    valve = 0.3F; lock += 2.0;
    std::cout<<cabin<<","<<lock<<","<<valve<<","<<leak<<","<<t<<","<<alarms<<"\n";
    return 0;
}
