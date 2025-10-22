// Context: Subway door interlock monitor

#include <iostream>
int main(){
    bool left=false, right=false;   // NC
    int cycles=0, errors=0;         // NC
    unsigned retries=0U, trips=0U;  // NC
    left=true; right=false;
    std::cout<<left<<","<<right<<","<<cycles<<","<<errors<<","<<retries<<","<<trips<<"\n";
    return 0;
}
