// Context: Smart greenhouse CO2 enrichment loop

#include <iostream>
int main(){
    double ppm=420.0, set=800.0;     // NC
    float valve=0.0F, leak=0.0F;     // NC
    unsigned ticks=0U, alarms=0U;    // NC
    valve += 0.1F; ppm += 10.0;
    if(ppm>set){ alarms++; }
    std::cout<<ppm<<","<<set<<","<<valve<<","<<leak<<","<<ticks<<","<<alarms<<"\n";
    return 0;
}
