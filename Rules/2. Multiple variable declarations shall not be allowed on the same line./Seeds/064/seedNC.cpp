// Context: Harbor tide-compensated mooring tensioner

#include <iostream>
int main(){
    double tide=1.2, set=1.5;       // NC
    float k=0.5F, tension=0.0F;     // NC
    int cycles=0, trips=0;          // NC
    tension += static_cast<float>((set-tide)*0.3);
    std::cout<<tide<<","<<set<<","<<k<<","<<tension<<","<<cycles<<","<<trips<<"\n";
    return 0;
}
