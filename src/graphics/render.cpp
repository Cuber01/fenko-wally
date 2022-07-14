#include <SDL.h>

#include <stdint.h>

#include "types.hpp"
#include "graphics/render.hpp"
#include "canvas.hpp"
#include "data.hpp"

CRenderHandler::CRenderHandler()
{
    // initialize video
    if( SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf( "SDL video failed to initialize. Error: %s\n", SDL_GetError() );
        exit(1);
    }

    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_SHOWN);

    // create window
	window = SDL_CreateWindow("FENKO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, window_flags);

	if(window == nullptr)
	{
		printf( "Window could not be created. SDL_Error: %s\n", SDL_GetError() );
        exit(1);
	} 

    // create renderer
    renderer = SDL_CreateRenderer(window, -1, 0); 

    if (renderer == nullptr)
    {
        printf("Renderer failed to initialize. Error: %s\n", SDL_GetError());
        exit(1);
    }
    
    // create surface
    surface = SDL_CreateRGBSurface(SDL_SWSURFACE, ROWS, COLS, 32, 0, 0, 0, 0);

    if(surface == nullptr)
    {
        printf("Failed to create surface: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_RenderSetScale(renderer, SCALE, SCALE);

}



void CRenderHandler::draw()
{
    clear();

    // main surface draw loop
    SDL_LockSurface(surface);

    unsigned char* pixels = (unsigned char*)surface -> pixels;
    Color value;

    for (uint16_t x = 0; x < ROWS; x++) {
        for (uint16_t y = 0; y < COLS; y++) {

            uint8_t colorId = grid[x][y];

            value = palette[colorId];

            if( not (value.r == 0 && value.g == 0 && value.b == 0)  )
            {

                pixels[4 * (y * surface -> w + x) + 2] = value.r;   //red
                pixels[4 * (y * surface -> w + x) + 1] = value.g;   //green
                pixels[4 * (y * surface -> w + x) + 0] = value.b;   //blue   

            }

        }
    }

    SDL_UnlockSurface(surface);

    // create texture from surface
    texture = SDL_CreateTextureFromSurface(renderer, surface); 
    
    // copy texture over to renderer
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture); //TODO keep one texture instead of destroying it every frame, see: SDL_Texture_Lock or SDL_Texture_Update
}

void CRenderHandler::clear()
{
    SDL_FillRect(surface, nullptr, 0x000000);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}
    