// Context: Barcode scanner digit buffer

// Seed 018 — NC: digit buffer decays to pointer
#include <iostream>
void parse_barcode(char digits[]) { // NC
    std::cout << "digit0=" << digits[0] << "\n";
}
int main(){
    char barcode[13] = "1234567890128";
    parse_barcode(barcode);
    return 0;
}