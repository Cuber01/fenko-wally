#ifndef __INPUT_HPP
#define __INPUT_HPP

#include <SDL.h>
#include <map>
#include "types.hpp"

class CInputBackend {
    
    private:
        SDL_Event event;
        intVector2D cursorPos;

        void handleInput(SDL_Event* e);

    public:
        std::map<int, bool> keyboard;

        bool mouseKeys[4];

        void updateInput();
        
};


#endif