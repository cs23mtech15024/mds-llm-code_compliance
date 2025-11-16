// Context: Audio equalizer preset header

// seed_034_NC.h
#pragma once
int seed034_bass = 5;
int seed034_treble = 7;
int seed034_eq_profile(int x) {
    return x + seed034_bass - seed034_treble;
}
