// Context: Harbor tide-compensated mooring tensioner

#include <iostream>
int main(){
    double tide=1.2;      // C
    double set=1.5;       // C
    float k=0.5F;         // C
    float tension=0.0F;   // C
    int cycles=0;         // C
    int trips=0;          // C
    tension += static_cast<float>((set-tide)*0.3);
    std::cout<<tide<<","<<set<<","<<k<<","<<tension<<","<<cycles<<","<<trips<<"\n";
    return 0;
}
