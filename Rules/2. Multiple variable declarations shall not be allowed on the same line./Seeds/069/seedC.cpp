// Context: Seismograph waveform analyzer

#include <iostream>
int main(){
    float amplitude=0.0F;  // C
    float freq=0.0F;       // C
    double magnitude=0.0;  // C
    double depth=0.0;      // C
    int events=0;          // C
    int alerts=0;          // C
    amplitude += 0.5F; events++;
    std::cout<<amplitude<<","<<freq<<","<<magnitude<<","<<depth<<","<<events<<","<<alerts<<"\n";
    return 0;
}
