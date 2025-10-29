// Context: Pharmaceutical reactor PH controller

#include <iostream>
int main(){
    double ph=7.0;        // C
    double target=7.2;    // C
    double acid=0.0;      // C
    double base=0.0;      // C
    unsigned it=0U;       // C
    unsigned maxIt=4U;    // C
    ph += 0.05; base += 0.02;
    std::cout<<ph<<","<<target<<","<<acid<<","<<base<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
