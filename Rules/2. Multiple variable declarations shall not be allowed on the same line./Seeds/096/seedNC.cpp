// Context: Chemical plant pH neutralization tank controller

#include <iostream>
int main(){
    double ph=6.2, tgt=7.0;        // NC
    float acid=0.0F, base=0.0F;    // NC
    int adds=0, alarms=0;          // NC
    base += 0.1F; ph += 0.2;
    std::cout<<ph<<","<<tgt<<","<<acid<<","<<base<<","<<adds<<","<<alarms<<"\n";
    return 0;
}
