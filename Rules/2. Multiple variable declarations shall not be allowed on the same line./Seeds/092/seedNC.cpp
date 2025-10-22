// Context: Airport baggage carousel jam detector

#include <iostream>
int main(){
    unsigned sensors=4U, trips=0U;  // NC
    float speed=0.8F, torque=0.0F;  // NC
    int jams=0, clears=0;           // NC
    torque += 0.3F; if(torque>1.0F){ ++jams; }
    std::cout<<sensors<<","<<trips<<","<<speed<<","<<torque<<","<<jams<<","<<clears<<"\n";
    return 0;
}
