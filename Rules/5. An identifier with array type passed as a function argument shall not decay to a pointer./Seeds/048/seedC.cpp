// Context: Capacitive touch button states

// Seed 048 — C: button states by reference
#include <iostream>
#include <cstdint>
bool is_button_pressed(std::uint8_t (&buttons)[12]) { // C
    return buttons[0] != 0;
}
int main(){
    std::uint8_t touch_buttons[12] = {1, 0, 0};
    std::cout << "btn0=" << is_button_pressed(touch_buttons) << "\n";
    return 0;
}