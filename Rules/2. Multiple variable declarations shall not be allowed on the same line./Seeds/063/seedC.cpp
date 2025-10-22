// Context: Factory conveyor vision reject gate

#include <iostream>
int main(){
    unsigned good=0U;      // C
    unsigned bad=0U;       // C
    float conf=0.0F;       // C
    float thr=0.85F;       // C
    bool jam=false;        // C
    bool reject=false;     // C
    conf = 0.9F; reject = (conf<thr); if(reject){ ++bad; } else { ++good; }
    std::cout<<good<<","<<bad<<","<<conf<<","<<thr<<","<<jam<<","<<reject<<"\n";
    return 0;
}
