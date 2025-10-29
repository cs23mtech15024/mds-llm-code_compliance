// Context: Airport baggage sorter diverter

#include <iostream>
int main(){
    unsigned bags=0U, jam=0U;        // NC
    float speed=1.0F, accel=0.0F;    // NC
    bool divert=false, halt=false;   // NC
    bags+=3U; accel=0.1F;
    std::cout<<bags<<","<<jam<<","<<speed<<","<<accel<<","<<divert<<","<<halt<<"\n";
    return 0;
}
