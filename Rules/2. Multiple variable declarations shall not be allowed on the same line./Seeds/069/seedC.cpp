// Context: Smart grid frequency droop emulator

#include <iostream>
int main(){
    double f=50.0;        // C
    double set=50.0;      // C
    float droop=0.05F;    // C
    float p=0.0F;         // C
    int steps=0;          // C
    int trips=0;          // C
    f -= 0.2; p += 0.1F;
    std::cout<<f<<","<<set<<","<<droop<<","<<p<<","<<steps<<","<<trips<<"\n";
    return 0;
}
