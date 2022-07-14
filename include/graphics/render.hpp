#ifndef __RENDER_HPP
#define __RENDER_HPP

#include <SDL.h>

class CRenderHandler {
    public:
        CRenderHandler();

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_Surface* surface = nullptr;
        SDL_Texture* texture = nullptr;

        void draw();
        void clear();

};


#endif