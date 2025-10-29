// Context: Planetary rover slip detection module

#include <iostream>
int main(){
    float omega=5.0F, v=0.5F;         // NC
    float mu=0.6F, slip=0.0F;         // NC
    unsigned frames=0U, alarms=0U;    // NC
    slip = (omega*0.1F - v);
    std::cout<<omega<<","<<v<<","<<mu<<","<<slip<<","<<frames<<","<<alarms<<"\n";
    return 0;
}
