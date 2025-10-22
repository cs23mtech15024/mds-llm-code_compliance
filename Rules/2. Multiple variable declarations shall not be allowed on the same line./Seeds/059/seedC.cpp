// Context: Smart city water leak localization

#include <iostream>
int main(){
    double flow=20.0;     // C
    double press=3.5;     // C
    float thr=0.5F;       // C
    float score=0.0F;     // C
    int zones=4;          // C
    int alarms=0;         // C
    score += 0.2F; flow += 1.0;
    std::cout<<flow<<","<<press<<","<<thr<<","<<score<<","<<zones<<","<<alarms<<"\n";
    return 0;
}
