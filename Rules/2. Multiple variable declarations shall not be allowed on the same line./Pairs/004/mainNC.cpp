// Context: Warehouse robot SLAM pose tracker

// ------ Non-Compliant Program (004_nc.cpp)
// Context: Warehouse robot SLAM pose tracker
// MISRA C++ 8-0-1 violations: multiple declarators per declaration
#include <iostream>
#include <iomanip>
#include <string>
#include <array>

namespace mon_004 {
    struct StatusEvent {
        int event_id;
        const char* description;
        unsigned timestamp;
    }; // OK
    
    static void log_event(const StatusEvent& evt) {
        std::cout << "[LOG] t=" << evt.timestamp
                 << " id=" << evt.event_id
                 << " desc=" << evt.description
                 << std::endl;
    }
    
    static bool check_status(unsigned value, unsigned threshold) {
        return value >= threshold;
    }
    
    void monitor() {
        float x=0.0F, y=0.0F;             // NC
        float vx=0.0F, vy=0.0F;             // NC
        unsigned it=0U, maxIt=5U;             // NC
        StatusEvent current_event{0, "system_init", 0U};
        const unsigned check_interval = 5U;
        const unsigned max_cycles = 20U;
        std::array<unsigned,20U> sensor_data{
            10U, 15U, 20U, 25U, 30U, 35U, 40U, 45U, 50U, 55U,
            60U, 65U, 70U, 75U, 80U, 85U, 90U, 95U, 100U, 105U
        };
        
        unsigned cycle_count = 0U;
        unsigned alert_count = 0U;
        
        for (std::size_t i = 0U; i < sensor_data.size(); ++i) {
            unsigned reading = sensor_data[i];
            cycle_count++;
            
            if (check_status(reading, 50U)) {
                alert_count++;
                current_event = StatusEvent{1, "threshold_exceeded", cycle_count};
                log_event(current_event);
            }
            
            if ((i % check_interval) == 0U) {
                current_event = StatusEvent{2, "periodic_check", cycle_count};
                log_event(current_event);
            }
            
            if (reading == 75U) {
                current_event = StatusEvent{3, "milestone_reached", cycle_count};
                log_event(current_event);
            }
            
            if ((i % 4U) == 0U) {
                std::cout << "cycle=" << cycle_count
                         << " reading=" << reading
                         << " alerts=" << alert_count
                         << std::endl;
            }
        }
        
        std::cout << "Monitoring completed. Total cycles=" << cycle_count
                 << " Total alerts=" << alert_count << std::endl;
    }
}

int main() {
    mon_004::monitor();
    return 0;
}
