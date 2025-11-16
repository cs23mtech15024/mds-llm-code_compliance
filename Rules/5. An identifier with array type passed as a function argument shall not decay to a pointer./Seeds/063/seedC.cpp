// Context: Kalman filter state vector

// Seed 063 — C: state vector by reference
#include <iostream>
void update_kalman_state(float (&state)[4]) { // C
    state[0] = state[0] * 0.99F;
    std::cout << "state0=" << state[0] << "\n";
}
int main(){
    float kalman_state[4] = {1.0F, 0.5F};
    update_kalman_state(kalman_state);
    return 0;
}