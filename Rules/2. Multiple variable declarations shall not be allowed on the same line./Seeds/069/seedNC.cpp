// Context: Smart grid frequency droop emulator

#include <iostream>
int main(){
    double f=50.0, set=50.0;         // NC
    float droop=0.05F, p=0.0F;       // NC
    int steps=0, trips=0;            // NC
    f -= 0.2; p += 0.1F;
    std::cout<<f<<","<<set<<","<<droop<<","<<p<<","<<steps<<","<<trips<<"\n";
    return 0;
}
