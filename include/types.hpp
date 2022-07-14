#ifndef __TYPES_HPP
#define __TYPES_HPP

#include <cstdint>

struct Vector2D {
    uint16_t x;
    uint16_t y;
};

struct intVector2D {
    int x;
    int y;
};

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

#endif