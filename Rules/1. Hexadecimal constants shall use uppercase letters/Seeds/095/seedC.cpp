// Context: MQTT message QoS level selector

// Seed 095 — C: uppercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t qos=0x02; // C (digits only)
    std::cout << "mqtt_qos=" << static_cast<unsigned>(qos) << "\n";
    return 0;
}