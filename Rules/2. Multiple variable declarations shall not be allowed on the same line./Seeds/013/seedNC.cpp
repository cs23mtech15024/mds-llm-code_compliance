// Context: Automated warehouse picker arm

#include <iostream>
int main(){
    long moves=0L, retries=0L;        // NC
    float x=0.0F, y=0.0F;             // NC
    bool jam=false, eStop=false;      // NC
    x+=1.0F; y+=-0.5F;
    std::cout<<moves<<","<<retries<<","<<x<<","<<y<<","<<jam<<","<<eStop<<"\n";
    return 0;
}
