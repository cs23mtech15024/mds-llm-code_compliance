// Context: Automated warehouse picker arm

#include <iostream>
int main(){
    long moves=0L;        // C
    long retries=0L;      // C
    float x=0.0F;         // C
    float y=0.0F;         // C
    bool jam=false;       // C
    bool eStop=false;     // C
    x+=1.0F; y+=-0.5F;
    std::cout<<moves<<","<<retries<<","<<x<<","<<y<<","<<jam<<","<<eStop<<"\n";
    return 0;
}
