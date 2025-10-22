// Context: Video analytics motion trigger

#include <iostream>
int main(){
    float thresh=0.4F, hyster=0.2F; // NC
    int detections=0, frames=0;     // NC
    bool armed=true, alarm=false;   // NC
    std::cout<<thresh<<","<<hyster<<","<<detections<<","<<frames<<","<<armed<<","<<alarm<<"\n";
    return 0;
}
