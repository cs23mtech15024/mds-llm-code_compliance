// Context: Database connection pool size header

// seed_029_NC.h
#pragma once
int seed029_pool_size = 16;
int seed029_max_clients() {
    return seed029_pool_size - 2;
}
