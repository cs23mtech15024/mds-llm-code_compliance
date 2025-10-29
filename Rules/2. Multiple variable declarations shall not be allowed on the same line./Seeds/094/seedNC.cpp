// Context: Stadium scoreboard graphics engine

#include <iostream>
int main(){
    int homeScore=0, awayScore=0;         // NC
    float brightness=0.8F, contrast=1.0F; // NC
    unsigned panels=120U, errors=0U;      // NC
    homeScore++; panels++;
    std::cout<<homeScore<<","<<awayScore<<","<<brightness<<","<<contrast<<","<<panels<<","<<errors<<"\n";
    return 0;
}
