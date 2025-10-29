// Context: Lunar habitat airlock pressure equalizer

#include <iostream>
int main(){
    double cabin=55.0;     // C
    double lock=10.0;      // C
    float valve=0.0F;      // C
    float leak=0.0F;       // C
    unsigned t=0U;         // C
    unsigned alarms=0U;    // C
    valve = 0.3F; lock += 2.0;
    std::cout<<cabin<<","<<lock<<","<<valve<<","<<leak<<","<<t<<","<<alarms<<"\n";
    return 0;
}
