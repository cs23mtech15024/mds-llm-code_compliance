// Context: CAN diagnostic PID filter

// Seed 036 — C: uppercase hex ACK mask
#include <iostream>
int main(){
    unsigned ackMask=0xFF; // C
    unsigned pid=0x7E0U; (void)pid;
    std::cout << "can_ack=0x" << std::hex << ackMask << "\n";
    return 0;
}