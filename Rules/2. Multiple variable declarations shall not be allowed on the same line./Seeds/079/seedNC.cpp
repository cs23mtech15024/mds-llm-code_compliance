// Context: Holographic projector phase array

#include <iostream>
int main(){
    float phaseX=0.0F, phaseY=0.0F;       // NC
    float intensity=1.0F, wavelength=532.0F; // NC
    int pixels=1920, lines=1080;          // NC
    phaseX += 0.1F; pixels++;
    std::cout<<phaseX<<","<<phaseY<<","<<intensity<<","<<wavelength<<","<<pixels<<","<<lines<<"\n";
    return 0;
}
