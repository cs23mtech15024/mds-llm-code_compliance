// Context: Planetary rover slip detection module

#include <iostream>
int main(){
    float omega=5.0F;      // C
    float v=0.5F;          // C
    float mu=0.6F;         // C
    float slip=0.0F;       // C
    unsigned frames=0U;    // C
    unsigned alarms=0U;    // C
    slip = (omega*0.1F - v);
    std::cout<<omega<<","<<v<<","<<mu<<","<<slip<<","<<frames<<","<<alarms<<"\n";
    return 0;
}
