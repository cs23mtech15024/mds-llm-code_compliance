// Context: Holographic projector phase array

#include <iostream>
int main(){
    float phaseX=0.0F;         // C
    float phaseY=0.0F;         // C
    float intensity=1.0F;      // C
    float wavelength=532.0F;   // C
    int pixels=1920;           // C
    int lines=1080;            // C
    phaseX += 0.1F; pixels++;
    std::cout<<phaseX<<","<<phaseY<<","<<intensity<<","<<wavelength<<","<<pixels<<","<<lines<<"\n";
    return 0;
}
