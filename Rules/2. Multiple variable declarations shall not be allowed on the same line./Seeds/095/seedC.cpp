// Context: Lottery ball randomizer validator

#include <iostream>
int main(){
    unsigned draws=0U;         // C
    unsigned balls=49U;        // C
    float temp=20.0F;          // C
    float humidity=50.0F;      // C
    int selections=6;          // C
    int matches=0;             // C
    draws++; balls--;
    std::cout<<draws<<","<<balls<<","<<temp<<","<<humidity<<","<<selections<<","<<matches<<"\n";
    return 0;
}
