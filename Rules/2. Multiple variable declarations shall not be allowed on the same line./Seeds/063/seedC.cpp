// Context: Chemical plant pH neutralization tank controller

#include <iostream>
int main(){
    double ph=6.2;       // C
    double tgt=7.0;      // C
    float acid=0.0F;     // C
    float base=0.0F;     // C
    int adds=0;          // C
    int alarms=0;        // C
    base += 0.1F; ph += 0.2;
    std::cout<<ph<<","<<tgt<<","<<acid<<","<<base<<","<<adds<<","<<alarms<<"\n";
    return 0;
}
