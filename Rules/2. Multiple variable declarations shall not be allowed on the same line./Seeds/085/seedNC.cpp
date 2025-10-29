// Context: Tsunami warning buoy data processor

#include <iostream>
int main(){
    double waveHeight=0.0, period=0.0;    // NC
    float latitude=0.0F, longitude=0.0F;  // NC
    unsigned samples=0U, warnings=0U;     // NC
    waveHeight += 0.1; samples++;
    std::cout<<waveHeight<<","<<period<<","<<latitude<<","<<longitude<<","<<samples<<","<<warnings<<"\n";
    return 0;
}
