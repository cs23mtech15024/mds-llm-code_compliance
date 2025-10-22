// Context: Airport baggage carousel jam detector

#include <iostream>
int main(){
    unsigned sensors=4U;  // C
    unsigned trips=0U;    // C
    float speed=0.8F;     // C
    float torque=0.0F;    // C
    int jams=0;           // C
    int clears=0;         // C
    torque += 0.3F; if(torque>1.0F){ ++jams; }
    std::cout<<sensors<<","<<trips<<","<<speed<<","<<torque<<","<<jams<<","<<clears<<"\n";
    return 0;
}
