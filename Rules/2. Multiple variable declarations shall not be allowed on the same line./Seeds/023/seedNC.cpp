// Context: Autonomous forklift proximity guard

#include <iostream>
int main(){
    float dist=3.0F, thresh=1.5F;   // NC
    bool slow=false, stop=false;    // NC
    unsigned events=0U, trips=0U;   // NC
    slow = (dist<thresh);
    std::cout<<dist<<","<<thresh<<","<<slow<<","<<stop<<","<<events<<","<<trips<<"\n";
    return 0;
}
