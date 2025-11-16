// Context: Home automation lighting profile

// seed_009_C.h
#pragma once
enum seed009_mode { SEED009_DAY, SEED009_NIGHT };
extern int seed009_default_level;
int seed009_get_level(seed009_mode m);
