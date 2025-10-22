// Context: EV charging bay scheduler

#include <iostream>
int main(){
    int active=2, queued=3;       // NC
    double pwrA=7.2, pwrB=7.2;    // NC
    bool peak=false, shed=false;  // NC
    std::cout<<active<<","<<queued<<","<<pwrA+pwrB<<","<<peak<<","<<shed<<"\n";
    return 0;
}
