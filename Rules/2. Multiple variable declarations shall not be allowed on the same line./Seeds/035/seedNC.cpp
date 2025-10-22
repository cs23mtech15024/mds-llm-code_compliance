// Context: Smart irrigation moisture guard

#include <iostream>
int main(){
    float soil=0.35F, thresh=0.30F;  // NC
    bool valve=false, alert=false;   // NC
    unsigned polls=0U, drops=0U;     // NC
    valve = (soil<thresh);
    std::cout<<soil<<","<<thresh<<","<<valve<<","<<alert<<","<<polls<<","<<drops<<"\n";
    return 0;
}
