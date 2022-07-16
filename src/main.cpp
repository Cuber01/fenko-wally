#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

#include "graphics/drawing_api.hpp"
#include "graphics/render.hpp"

#include "input/input_api.hpp"
#include "sound/sound.hpp"

#include "api/wally_fenko.hpp"

extern "C"
{
    #include "wally/main.h"
    #include "wally/vm/vm.h"
}

CRenderHandler renderer;
CInput         input;
CDraw          draw;
CSound         sound;


void quit()
{
    // destroy the renderer and the window
    SDL_DestroyRenderer( renderer.renderer );
    SDL_DestroyWindow( renderer.window );

    // quit both SDL_Mix and SDL2
    Mix_Quit();
    SDL_Quit();
}


int main(int argc, const char* argv[])
{
    initVM();
    defineFenko(vm.nativeEnvironment->values);
    runWally(argc, argv);

    quit();

    return 0;
}

