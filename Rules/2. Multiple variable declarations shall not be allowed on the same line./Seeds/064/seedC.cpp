// Context: Smart greenhouse CO2 enrichment loop

#include <iostream>
int main(){
    double ppm=420.0;      // C
    double set=800.0;      // C
    float valve=0.0F;      // C
    float leak=0.0F;       // C
    unsigned ticks=0U;     // C
    unsigned alarms=0U;    // C
    valve += 0.1F; ppm += 10.0; if(ppm>set){ alarms++; }
    std::cout<<ppm<<","<<set<<","<<valve<<","<<leak<<","<<ticks<<","<<alarms<<"\n";
    return 0;
}
