#include <SDL.h>
#include "input/input_api.hpp"
#include <map>

void CInput::updateInput()
{
    SDL_Delay(10);

    inputBackend.updateInput();
}

bool CInput::isButtonPressed(SDL_Keycode button)
{
    if (inputBackend.keyboard[button]) {
        return true;
    } 

    return false;
} 

bool CInput::isMouseButtonPressed(uint8_t button) 
{
    if (inputBackend.mouseKeys[button])
    {
        return true;
    }

    return false;
}