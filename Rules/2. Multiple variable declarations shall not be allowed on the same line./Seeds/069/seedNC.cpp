// Context: Seismograph waveform analyzer

#include <iostream>
int main(){
    float amplitude=0.0F, freq=0.0F;  // NC
    double magnitude=0.0, depth=0.0;  // NC
    int events=0, alerts=0;           // NC
    amplitude += 0.5F; events++;
    std::cout<<amplitude<<","<<freq<<","<<magnitude<<","<<depth<<","<<events<<","<<alerts<<"\n";
    return 0;
}
