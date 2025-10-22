// Context: Smart city water leak localization

#include <iostream>
int main(){
    double flow=20.0, press=3.5;    // NC
    float thr=0.5F, score=0.0F;     // NC
    int zones=4, alarms=0;          // NC
    score += 0.2F; flow += 1.0;
    std::cout<<flow<<","<<press<<","<<thr<<","<<score<<","<<zones<<","<<alarms<<"\n";
    return 0;
}
