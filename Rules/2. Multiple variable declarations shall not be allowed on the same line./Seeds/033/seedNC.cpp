// Context: Pharmaceutical reactor PH controller

#include <iostream>
int main(){
    double ph=7.0, target=7.2;       // NC
    double acid=0.0, base=0.0;       // NC
    unsigned it=0U, maxIt=4U;        // NC
    ph += 0.05; base += 0.02;
    std::cout<<ph<<","<<target<<","<<acid<<","<<base<<","<<it<<","<<maxIt<<"\n";
    return 0;
}
