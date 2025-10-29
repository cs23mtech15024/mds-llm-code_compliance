// Context: Slot machine payout calculator

#include <iostream>
int main(){
    unsigned credits=100U;     // C
    unsigned bet=5U;           // C
    float payoutRate=0.95F;    // C
    float jackpot=0.0F;        // C
    int spins=0;               // C
    int wins=0;                // C
    credits -= bet; spins++;
    std::cout<<credits<<","<<bet<<","<<payoutRate<<","<<jackpot<<","<<spins<<","<<wins<<"\n";
    return 0;
}
