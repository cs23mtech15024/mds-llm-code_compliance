// Context: Smart irrigation moisture guard

#include <iostream>
int main(){
    float soil=0.35F;      // C
    float thresh=0.30F;    // C
    bool valve=false;      // C
    bool alert=false;      // C
    unsigned polls=0U;     // C
    unsigned drops=0U;     // C
    valve = (soil<thresh);
    std::cout<<soil<<","<<thresh<<","<<valve<<","<<alert<<","<<polls<<","<<drops<<"\n";
    return 0;
}
