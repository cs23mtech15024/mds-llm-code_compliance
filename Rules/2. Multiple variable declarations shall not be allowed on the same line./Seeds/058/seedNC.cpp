// Context: Microgrid black-start sequencer

#include <iostream>
int main(){
    unsigned gens=2U, loads=5U;     // NC
    float freq=0.0F, volt=0.0F;     // NC
    int steps=0, fails=0;           // NC
    steps += 1; freq += 0.1F; volt += 0.2F;
    std::cout<<gens<<","<<loads<<","<<freq<<","<<volt<<","<<steps<<","<<fails<<"\n";
    return 0;
}
