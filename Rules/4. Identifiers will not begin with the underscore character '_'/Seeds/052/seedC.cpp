// Context: Exponential moving average

// Seed 052 — C: function and parameters without underscore prefix
#include <iostream>
float ema_update(float prev, float new_val, float alpha) { // C
    return alpha * new_val + (1.0F - alpha) * prev;
}
int main(){
    std::cout << "ema=" << ema_update(100.0F, 105.0F, 0.2F) << "\n";
    return 0;
}