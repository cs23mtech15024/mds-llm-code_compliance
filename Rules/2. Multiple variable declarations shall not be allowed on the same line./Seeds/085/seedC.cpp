// Context: Tsunami warning buoy data processor

#include <iostream>
int main(){
    double waveHeight=0.0; // C
    double period=0.0;     // C
    float latitude=0.0F;   // C
    float longitude=0.0F;  // C
    unsigned samples=0U;   // C
    unsigned warnings=0U;  // C
    waveHeight += 0.1; samples++;
    std::cout<<waveHeight<<","<<period<<","<<latitude<<","<<longitude<<","<<samples<<","<<warnings<<"\n";
    return 0;
}
