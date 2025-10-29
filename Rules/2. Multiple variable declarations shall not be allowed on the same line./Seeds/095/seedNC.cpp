// Context: Lottery ball randomizer validator

#include <iostream>
int main(){
    unsigned draws=0U, balls=49U;         // NC
    float temp=20.0F, humidity=50.0F;     // NC
    int selections=6, matches=0;          // NC
    draws++; balls--;
    std::cout<<draws<<","<<balls<<","<<temp<<","<<humidity<<","<<selections<<","<<matches<<"\n";
    return 0;
}
