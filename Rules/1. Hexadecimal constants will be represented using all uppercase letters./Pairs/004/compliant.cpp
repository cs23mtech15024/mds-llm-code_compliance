// ------ Compliant
// Pair 4 — Seed: 35u -> 35U
// Context: BFS traversal of mission waypoints in an autonomous missile system.
// Violation: lowercase 'u' suffix could be less visible in critical code review.
// Source: MISRA C++ Rule 2-13-4 (literal suffixes shall be upper case).

#include <iostream>
#include <vector>
#include <queue>

struct Waypoint {
    unsigned id;
    std::vector<unsigned> neighbors;
};

class MissionPlanner_C {
public:
    MissionPlanner_C() {
        // Seed literal corrected here: uppercase 'U'
        waypoints.resize(35U); // C
        for (unsigned i = 0; i < waypoints.size(); ++i) {
            waypoints[i].id = i;
            if (i + 1 < waypoints.size()) {
                waypoints[i].neighbors.push_back(i + 1);
            }
        }
    }

    void bfs(unsigned start) const {
        std::vector<bool> visited(waypoints.size(), false);
        std::queue<unsigned> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            unsigned cur = q.front();
            q.pop();
            std::cout << "[C] Visiting waypoint " << cur << "\n";

            for (auto n : waypoints[cur].neighbors) {
                if (!visited[n]) {
                    visited[n] = true;
                    q.push(n);
                }
            }
        }
    }

private:
    std::vector<Waypoint> waypoints;
};

int main() {
    MissionPlanner_C planner;
    planner.bfs(0);
    return 0;
}