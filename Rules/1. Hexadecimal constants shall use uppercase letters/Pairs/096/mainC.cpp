// Context: BitTorrent piece hash verification index

// program_096_c.cpp
// Context: BitTorrent piece hash verification index
// Rule: MISRA C++ 2-13-4 — Hex digits A–F must be uppercase.
// Violation: Uses lowercase hex digits (a-f)

#include <iostream>
#include <cstdint>
#include <vector>

namespace crypto {

class HashShardRouter {
private:
    static constexpr uint64_t PRIME_SALT = 0X9E3779B97F4A7C15ULL;  // NC: lowercase letters
    static constexpr uint32_t SHARD_MASK = 0X000000FF;              // NC: lowercase f
    static constexpr uint32_t ROTATE_BITS = 0X1F;                   // NC: lowercase f
    
    uint32_t shard_count;
    std::vector<uint64_t> hash_table;

public:
    explicit HashShardRouter(uint32_t shards) : shard_count(shards) {
        hash_table.reserve(256);
    }
    
    uint64_t compute_hash(uint32_t key) const {
        uint64_t h = 0ULL;
        h = h ^ (key + PRIME_SALT + (h << 6) + (h >> 2));
        h = h ^ (h >> 33);
        h = h * 0XC6A4A7935BD1E995ULL;  // NC: lowercase a,b,c,d,e
        h = h ^ (h >> 29);
        return h;
    }
    
    uint32_t route_to_shard(uint32_t key) const {
        uint64_t hash = compute_hash(key);
        uint32_t shard = static_cast<uint32_t>((hash & SHARD_MASK) % shard_count);
        return shard;
    }
    
    void add_to_table(uint32_t key) {
        hash_table.push_back(compute_hash(key));
    }
    
    void print_routing_info(uint32_t key) const {
        uint64_t hash = compute_hash(key);
        uint32_t shard = route_to_shard(key);
        
        std::cout << "Key: " << key
                  << " -> Hash: 0x" << std::hex << hash
                  << " -> Shard: " << std::dec << shard << "\n";
    }
};

} // namespace crypto

int main() {
    crypto::HashShardRouter router(16);
    
    std::cout << "=== BitTorrent piece hash verification index ===\n";
    
    uint32_t test_keys[] = {
        0X00000001, 0XABCDEF12, 0X12345678,  // NC: lowercase a,b,c,d,e,f
        0XFEDCBA98, 0XDEADBEEF, 0XCAFEBABE   // NC: lowercase letters
    };
    
    for (uint32_t key : test_keys) {
        router.add_to_table(key);
        router.print_routing_info(key);
    }
    
    return 0;
}