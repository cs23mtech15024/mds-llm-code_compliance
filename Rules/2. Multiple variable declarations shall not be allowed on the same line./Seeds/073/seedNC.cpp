// Context: DNA sequencer base caller

#include <iostream>
int main(){
    float qualA=0.9F, qualT=0.9F, qualC=0.9F, qualG=0.9F; // NC
    int reads=0, errors=0;                                 // NC
    reads++;
    std::cout<<qualA<<","<<qualT<<","<<qualC<<","<<qualG<<","<<reads<<","<<errors<<"\n";
    return 0;
}
