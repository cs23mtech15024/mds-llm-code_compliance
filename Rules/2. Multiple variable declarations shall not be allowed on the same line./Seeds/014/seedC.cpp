// Context: Subway door interlock monitor

#include <iostream>
int main(){
    bool left=false;        // C
    bool right=false;       // C
    int cycles=0;           // C
    int errors=0;           // C
    unsigned retries=0U;    // C
    unsigned trips=0U;      // C
    left=true; right=false;
    std::cout<<left<<","<<right<<","<<cycles<<","<<errors<<","<<retries<<","<<trips<<"\n";
    return 0;
}
