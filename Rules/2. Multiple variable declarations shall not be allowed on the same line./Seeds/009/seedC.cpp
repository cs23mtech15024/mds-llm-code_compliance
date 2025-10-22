// Context: Video analytics motion trigger

#include <iostream>
int main(){
    float thresh=0.4F;     // C
    float hyster=0.2F;     // C
    int detections=0;      // C
    int frames=0;          // C
    bool armed=true;       // C
    bool alarm=false;      // C
    std::cout<<thresh<<","<<hyster<<","<<detections<<","<<frames<<","<<armed<<","<<alarm<<"\n";
    return 0;
}
