#include <memory.h>
#include <ctgmath>

#include "graphics/drawing_api.hpp"
#include "canvas.hpp"

void CDraw::pset(uint16_t x, uint16_t y, uint8_t c)
{
    grid[x][y] = c;
}

uint8_t CDraw::pget(uint16_t x, uint16_t y)
{
    return grid[x][y];
}

void CDraw::rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t c)
{

    for(uint16_t i = 0; i < w; i++)
    {
        pset(x+i, y, c);

        /*

        ────────

        */

        if(i == w-1)
        {
            for(uint16_t j = 0; j < h; j++)
            {
                pset(x+i, y+j, c);
            }


            /*

            ────────╮
                    │
                    │
                    │
                    

            */
        }
    }


    for(uint16_t i = 0; i < h; i++)
    {
        pset(x, y+i, c);

        /*
        
        ╭───────╮
        │       │
        │       │
        │       │
        

        */

        if(i == h-1)
        {
            for(uint16_t j = 0; j < w; j++)
            {
                pset(x+j, y+i, c);
            }


            /*

            ╭───────╮
            │       │
            │       │
            │       │  
            ╰───────╯

            */

        }
    }



}

void CDraw::rectfill(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t c)
{
    for(uint16_t i = 0; i < w; i++)
    {
        for(uint16_t j = 0; j < h; j++)
        {
            pset(x+i, y+j, c);
        }
    }
    
}

void CDraw::circ(uint16_t x, uint16_t y, uint16_t r,  uint8_t c)
{

    int32_t  offset_x = 0;
    int32_t  offset_y = r;

    uint16_t d = r - 1;

    while (offset_y >= offset_x) {
        pset(x + offset_x, y + offset_y, c);
        pset(x + offset_y, y + offset_x, c);

        pset(x - offset_x, y + offset_y, c);
        pset(x - offset_y, y + offset_x, c);

        pset(x + offset_x, y - offset_y, c);
        pset(x + offset_y, y - offset_x, c);
        
        pset(x - offset_x, y - offset_y, c);
        pset(x - offset_y, y - offset_x, c);


        if (d >= 2 * offset_x) {
            d -= 2 * offset_x + 1;
            offset_x +=1;
        }
        else if (d < 2 * (r - offset_y)) {
            d += 2 * offset_y - 1;
            offset_y -= 1;
        }
        else {
            d += 2 * (offset_y - offset_x - 1);
            offset_y -= 1;
            offset_x += 1;
        }
    }

}

void CDraw::circfill(uint16_t x, uint16_t y, uint16_t r,  uint8_t c)
{

    int32_t  offset_x = 0;
    int32_t  offset_y = r;

    uint16_t d = r - 1;

    while (offset_y >= offset_x) {

        line(x - offset_y, y + offset_x, x + offset_y, y + offset_x, c);
        line(x - offset_x, y + offset_y, x + offset_x, y + offset_y, c);
        line(x - offset_x, y - offset_y, x + offset_x, y - offset_y, c);
        line(x - offset_y, y - offset_x, x + offset_y, y - offset_x, c);

        if (d >= 2*offset_x) {
            d -= 2*offset_x + 1;
            offset_x +=1;
        }
        else if (d < 2 * (r - offset_y)) {
            d += 2 * offset_y - 1;
            offset_y -= 1;
        }
        else {
            d += 2 * (offset_y - offset_x - 1);
            offset_y -= 1;
            offset_x += 1;
        }
    
    }
}

void CDraw::line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t c)
{
    uint16_t x, y, xe, ye, i;

    int16_t dx = x2 - x1;
    int16_t dy = y2 - y1;

    uint16_t dx1 = abs(dx);
    uint16_t dy1 = abs(dy);

    int16_t px = 2 * dy1 - dx1;
    int16_t py = 2 * dx1 - dy1;
    
    if (dy1 <= dx1)
    {
        if (dx >= 0)
        {
            x = x1;
            y = y1;
            xe = x2;
        }
        else
        {
            x = x2;
            y = y2;
            xe = x1;
        }
        
        pset(x, y, c);
        
        for (i = 0; x < xe; i++)
        {
            x = x + 1;
            if (px < 0)
            {
                px = px + 2 * dy1;
            }
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                {
                    y = y + 1;
                }
                else
                {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }

            pset(x, y, c);
        }
    }
    else
    {
        if (dy >= 0)
        {
            x = x1;
            y = y1;
            ye = y2;
        }
        else
        {
            x = x2;
            y = y2;
            ye = y1;
        }
        pset(x, y, c);
        for (i = 0; y < ye; i++)
        {
            y = y + 1;
            if (py <= 0)
            {
                py = py + 2 * dx1;
            }
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                {
                    x = x + 1;
                }
                else
                {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }

            pset(x, y, c);
        }
    }
}

void CDraw::clear(uint8_t c)
{
    memset( grid, c, sizeof(grid) );
}