// Context: MQTT message QoS level selector

// Seed 095 — NC: lowercase hex
#include <cstdint>
#include <iostream>
int main(){
    std::uint8_t qos=0x02; // NC: QoS 2
    std::cout << "mqtt_qos=" << static_cast<unsigned>(qos) << "\n";
    return 0;
}