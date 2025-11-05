// Context: Financial transaction validator function — Expanded program

// ------ Non-Compliant Program (001_nc.cpp)
// Context: Financial transaction validator function
// MISRA C++: Identifiers must not begin with '_'
// NC: several identifiers begin with '_'
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cctype>

namespace _txn_rule_001 {

struct _Record {
    int id;
    std::string name;
    int amount;
};

static bool _isLettersOnly(const std::string &s) {
    for (unsigned char ch : s) {
        if (std::isalpha(ch) == 0) { return false; }
    }
    return s.size() >= 3U;
}

static bool _isAmountValid(int v) {
    return (v >= 0) && (v <= 1000000);
}

class _Processor {
public:
    explicit _Processor(std::vector<_Record> recs)
    : _recs(std::move(recs)) { }

    void _run() {
        auto filtered = _filterValid();
        _log(filtered);
        int sum = std::accumulate(filtered.begin(), filtered.end(), 0,
            [](int acc, const _Record &r){ return acc + r.amount; });
        std::cout << "sum=" << sum << " avg=" << _avg(filtered) << std::endl;
    }

private:
    std::vector<_Record> _recs;

    std::vector<_Record> _filterValid() const {
        std::vector<_Record> out;
        out.reserve(_recs.size());
        for (const auto &r : _recs) {
            if (((r.id % 2) == 0) && _isLettersOnly(r.name) && _isAmountValid(r.amount)) {
                out.push_back(r);
            }
        }
        return out;
    }

    void _log(const std::vector<_Record> &v) const {
        int _valid_count = 0;
        for (const auto &r : v) {
            std::cout << "[rec] id=" << r.id << " name=" << r.name << " amt=" << r.amount << std::endl;
            ++_valid_count;
        }
        std::cout << "valid=" << _valid_count << std::endl;
    }

    double _avg(const std::vector<_Record> &v) const {
        if (v.empty()) { return 0.0; }
        long long _total = 0;
        for (const auto &r : v) { _total += r.amount; }
        return static_cast<double>(_total) / static_cast<double>(v.size());
    }
};

} // namespace _txn_rule_001

int main() {
    using namespace _txn_rule_001;
    std::vector<_Record> data;
    data.push_back({0, "Alpha", 10});
    data.push_back({1, "Beta", 5});
    data.push_back({2, "Gamma", 12});
    data.push_back({3, "Delta", 7});
    data.push_back({4, "Epsilon", 9});
    _Processor p(data);
    p._run();
    return 0;
}
