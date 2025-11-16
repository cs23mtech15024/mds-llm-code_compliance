// Context: Filesystem cache parameters header

// seed_013_NC.h
#pragma once
// NC: cache size and eviction helper in header
#include <cstddef>
std::size_t seed013_cache_size = 4096; // NC

bool seed013_should_evict(std::size_t used) { // NC
    return used > seed013_cache_size;
}
