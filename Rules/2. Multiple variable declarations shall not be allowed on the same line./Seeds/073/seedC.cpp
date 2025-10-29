// Context: DNA sequencer base caller

#include <iostream>
int main(){
    float qualA=0.9F;      // C
    float qualT=0.9F;      // C
    float qualC=0.9F;      // C
    float qualG=0.9F;      // C
    int reads=0;           // C
    int errors=0;          // C
    reads++;
    std::cout<<qualA<<","<<qualT<<","<<qualC<<","<<qualG<<","<<reads<<","<<errors<<"\n";
    return 0;
}
