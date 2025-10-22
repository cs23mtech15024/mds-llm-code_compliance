// Context: EV charging bay scheduler

#include <iostream>
int main(){
    int active=2;          // C
    int queued=3;          // C
    double pwrA=7.2;       // C
    double pwrB=7.2;       // C
    bool peak=false;       // C
    bool shed=false;       // C
    std::cout<<active<<","<<queued<<","<<pwrA+pwrB<<","<<peak<<","<<shed<<"\n";
    return 0;
}
