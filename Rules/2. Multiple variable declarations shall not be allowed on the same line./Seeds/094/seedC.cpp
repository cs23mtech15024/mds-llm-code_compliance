// Context: Stadium scoreboard graphics engine

#include <iostream>
int main(){
    int homeScore=0;           // C
    int awayScore=0;           // C
    float brightness=0.8F;     // C
    float contrast=1.0F;       // C
    unsigned panels=120U;      // C
    unsigned errors=0U;        // C
    homeScore++; panels++;
    std::cout<<homeScore<<","<<awayScore<<","<<brightness<<","<<contrast<<","<<panels<<","<<errors<<"\n";
    return 0;
}
