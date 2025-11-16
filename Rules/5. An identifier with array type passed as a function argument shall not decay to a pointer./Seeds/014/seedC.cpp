// Context: Stepper motor step sequence

// Seed 014 — C: step sequence by reference
#include <iostream>
#include <cstdint>
void execute_steps(std::uint8_t (&sequence)[4]) { // C
    std::cout << "step0=0x" << std::hex << static_cast<int>(sequence[0]) << "\n";
}
int main(){
    std::uint8_t motor_steps[4] = {0x01, 0x02, 0x04, 0x08};
    execute_steps(motor_steps);
    return 0;
}