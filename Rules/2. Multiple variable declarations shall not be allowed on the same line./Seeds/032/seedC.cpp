// Context: Pipeline pressure relief supervisor

#include <iostream>
int main(){
    float p=55.0F;        // C
    float limit=60.0F;    // C
    int warns=0;          // C
    int trips=0;          // C
    bool relieve=false;   // C
    bool leak=false;      // C
    relieve = (p>limit);
    std::cout<<p<<","<<limit<<","<<warns<<","<<trips<<","<<relieve<<","<<leak<<"\n";
    return 0;
}
