// Context: Filesystem cache parameters header

// seed_013_C.h
#pragma once
#include <cstddef>
extern std::size_t seed013_cache_size;
bool seed013_should_evict(std::size_t used);
