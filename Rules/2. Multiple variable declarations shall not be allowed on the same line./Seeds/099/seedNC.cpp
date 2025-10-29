// Context: Piano tuner frequency analyzer

#include <iostream>
int main(){
    double freq=440.0, detune=0.0;        // NC
    float amplitude=1.0F, phase=0.0F;     // NC
    int key=49, octave=4;                 // NC
    freq += 0.1; key++;
    std::cout<<freq<<","<<detune<<","<<amplitude<<","<<phase<<","<<key<<","<<octave<<"\n";
    return 0;
}
