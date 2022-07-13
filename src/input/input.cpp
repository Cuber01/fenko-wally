#include <SDL.h>

#include "input/input.hpp"
#include "main.hpp"

void CInputBackend::updateInput()
{
    while (SDL_PollEvent(&event))
    {
        handleInput(&event);
    }
}

void CInputBackend::handleInput(SDL_Event* event)
{

    // mouse
    switch (event->type)
    {
        
        case SDL_MOUSEMOTION:
            SDL_GetMouseState( &cursorPos.x, &cursorPos.y );
            break;

        case SDL_MOUSEBUTTONDOWN:
            mouseKeys[event->button.button] = true;
            break;

        case SDL_MOUSEBUTTONUP:
            mouseKeys[event->button.button] = false;
            break;

    }

    // keyboard and quit
    switch (event->type)
    {

    case SDL_KEYDOWN:
        keyboard[event->key.keysym.sym] = true;
        break;

    case SDL_KEYUP:
        keyboard[event->key.keysym.sym] = false;
        break;

    case SDL_QUIT:
        running = false;
        break;

    }

}