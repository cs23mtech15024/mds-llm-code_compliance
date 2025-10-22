// Context: Airport baggage sorter diverter

#include <iostream>
int main(){
    unsigned bags=0U;     // C
    unsigned jam=0U;      // C
    float speed=1.0F;     // C
    float accel=0.0F;     // C
    bool divert=false;    // C
    bool halt=false;      // C
    bags+=3U; accel=0.1F;
    std::cout<<bags<<","<<jam<<","<<speed<<","<<accel<<","<<divert<<","<<halt<<"\n";
    return 0;
}
