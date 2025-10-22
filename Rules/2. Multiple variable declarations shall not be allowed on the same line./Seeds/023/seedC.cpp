// Context: Autonomous forklift proximity guard

#include <iostream>
int main(){
    float dist=3.0F;      // C
    float thresh=1.5F;    // C
    bool slow=false;      // C
    bool stop=false;      // C
    unsigned events=0U;   // C
    unsigned trips=0U;    // C
    slow = (dist<thresh);
    std::cout<<dist<<","<<thresh<<","<<slow<<","<<stop<<","<<events<<","<<trips<<"\n";
    return 0;
}
