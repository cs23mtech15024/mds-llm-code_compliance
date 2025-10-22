// Context: Microgrid black-start sequencer

#include <iostream>
int main(){
    unsigned gens=2U;     // C
    unsigned loads=5U;    // C
    float freq=0.0F;      // C
    float volt=0.0F;      // C
    int steps=0;          // C
    int fails=0;          // C
    steps += 1; freq += 0.1F; volt += 0.2F;
    std::cout<<gens<<","<<loads<<","<<freq<<","<<volt<<","<<steps<<","<<fails<<"\n";
    return 0;
}
