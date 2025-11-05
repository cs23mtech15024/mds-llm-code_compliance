// Context: Financial transaction validator function — Expanded program

// ------ Compliant Program (001_c.cpp)
// Context: Financial transaction validator function
// MISRA C++: Identifiers must not begin with '_'
// C: no identifiers begin with '_'
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cctype>

namespace txn_rule_001 {

struct Record {
    int id;
    std::string name;
    int amount;
};

static bool isLettersOnly(const std::string &s) {
    for (unsigned char ch : s) {
        if (std::isalpha(ch) == 0) { return false; }
    }
    return s.size() >= 3U;
}

static bool isAmountValid(int v) {
    return (v >= 0) && (v <= 1000000);
}

class Processor {
public:
    explicit Processor(std::vector<Record> recs)
    : recs_(std::move(recs)) { }

    void run() {
        auto filtered = filterValid();
        log(filtered);
        int sum = std::accumulate(filtered.begin(), filtered.end(), 0,
            [](int acc, const Record &r){ return acc + r.amount; });
        std::cout << "sum=" << sum << " avg=" << avg(filtered) << std::endl;
    }

private:
    std::vector<Record> recs_;

    std::vector<Record> filterValid() const {
        std::vector<Record> out;
        out.reserve(recs_.size());
        for (const auto &r : recs_) {
            if (((r.id % 2) == 0) && isLettersOnly(r.name) && isAmountValid(r.amount)) {
                out.push_back(r);
            }
        }
        return out;
    }

    void log(const std::vector<Record> &v) const {
        int valid_count = 0;
        for (const auto &r : v) {
            std::cout << "[rec] id=" << r.id << " name=" << r.name << " amt=" << r.amount << std::endl;
            ++valid_count;
        }
        std::cout << "valid=" << valid_count << std::endl;
    }

    double avg(const std::vector<Record> &v) const {
        if (v.empty()) { return 0.0; }
        long long total = 0;
        for (const auto &r : v) { total += r.amount; }
        return static_cast<double>(total) / static_cast<double>(v.size());
    }
};

} // namespace txn_rule_001

int main() {
    using namespace txn_rule_001;
    std::vector<Record> data;
    data.push_back({0, "Alpha", 10});
    data.push_back({1, "Beta", 5});
    data.push_back({2, "Gamma", 12});
    data.push_back({3, "Delta", 7});
    data.push_back({4, "Epsilon", 9});
    Processor p(data);
    p.run();
    return 0;
}
