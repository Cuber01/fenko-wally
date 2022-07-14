#include <SDL.h>

#include "input/input.hpp"

void CInputBackend::updateInput()
{
    while (SDL_PollEvent(&event))
    {
        handleInput(&event);
    }
}

void CInputBackend::handleInput(SDL_Event* e)
{

    // mouse
    switch (e->type)
    {
        
        case SDL_MOUSEMOTION:
            SDL_GetMouseState( &cursorPos.x, &cursorPos.y );
            break;

        case SDL_MOUSEBUTTONDOWN:
            mouseKeys[e->button.button] = true;
            break;

        case SDL_MOUSEBUTTONUP:
            mouseKeys[e->button.button] = false;
            break;

    }

    // keyboard and quit
    switch (e->type)
    {

    case SDL_KEYDOWN:
        keyboard[e->key.keysym.sym] = true;
        break;

    case SDL_KEYUP:
        keyboard[e->key.keysym.sym] = false;
        break;

    case SDL_QUIT:
        // TODO Handle quit
        break;

    }

}