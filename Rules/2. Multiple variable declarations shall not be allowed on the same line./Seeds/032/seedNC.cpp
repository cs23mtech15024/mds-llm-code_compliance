// Context: Pipeline pressure relief supervisor

#include <iostream>
int main(){
    float p=55.0F, limit=60.0F;      // NC
    int warns=0, trips=0;            // NC
    bool relieve=false, leak=false;  // NC
    relieve = (p>limit);
    std::cout<<p<<","<<limit<<","<<warns<<","<<trips<<","<<relieve<<","<<leak<<"\n";
    return 0;
}
