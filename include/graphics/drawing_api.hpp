#ifndef __DRAW_HPP
#define __DRAW_HPP

#include <cstdint>

class CDraw {

    public:

        // Sets pixel at xy coordinates to c color
        void pset(uint16_t x, uint16_t y, uint8_t c);

        // Returns pixel color at xy coordinates
        uint8_t pget(uint16_t x, uint16_t y);

        // Draw an empty rectangle from x y (up left corner) to x2 y2 (down right corner) using c color
        void rect(uint16_t x, uint16_t y, uint16_t x2, uint16_t y2, uint8_t c);

        // Draw a filled rectangle from x y with w width and h height using c color
        void rectfill(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t c);

        // Draw a line from x1 y1 to x2 y2 with c color
        void line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,  uint8_t c);

        // Draw a an empty circle on x y with r radius in c color
        void circ(uint16_t x, uint16_t y, uint16_t r,  uint8_t c);

        // Draw a filled circle on x y with r radius in c color
        void circfill(uint16_t x, uint16_t y, uint16_t r,  uint8_t c);

        // Clears the screen using c color
        void clear(uint8_t c);

};


#endif