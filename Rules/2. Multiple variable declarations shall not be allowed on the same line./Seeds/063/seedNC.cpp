// Context: Factory conveyor vision reject gate

#include <iostream>
int main(){
    unsigned good=0U, bad=0U;        // NC
    float conf=0.0F, thr=0.85F;      // NC
    bool jam=false, reject=false;    // NC
    conf = 0.9F; reject = (conf<thr);
    if(reject){ ++bad; } else { ++good; }
    std::cout<<good<<","<<bad<<","<<conf<<","<<thr<<","<<jam<<","<<reject<<"\n";
    return 0;
}
