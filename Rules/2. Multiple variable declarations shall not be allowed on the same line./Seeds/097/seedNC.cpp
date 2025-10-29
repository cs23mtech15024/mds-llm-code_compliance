// Context: Slot machine payout calculator

#include <iostream>
int main(){
    unsigned credits=100U, bet=5U;        // NC
    float payoutRate=0.95F, jackpot=0.0F; // NC
    int spins=0, wins=0;                  // NC
    credits -= bet; spins++;
    std::cout<<credits<<","<<bet<<","<<payoutRate<<","<<jackpot<<","<<spins<<","<<wins<<"\n";
    return 0;
}
