// Context: Piano tuner frequency analyzer

#include <iostream>
int main(){
    double freq=440.0;         // C
    double detune=0.0;         // C
    float amplitude=1.0F;      // C
    float phase=0.0F;          // C
    int key=49;                // C
    int octave=4;              // C
    freq += 0.1; key++;
    std::cout<<freq<<","<<detune<<","<<amplitude<<","<<phase<<","<<key<<","<<octave<<"\n";
    return 0;
}
