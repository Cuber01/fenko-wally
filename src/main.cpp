#include <SDL.h>
#include <SDL_mixer.h>

#include "graphics/drawing_api.hpp"
#include "graphics/sprite.hpp"
#include "graphics/render.hpp"

#include "input/input_api.hpp"
#include "sound/sound.hpp"

#include "api/wally_fenko.hpp"

bool running = true;

CRenderHandler renderer;
CInput         input;
CDraw          draw;
CSound         sound;
CSprite        sprite;

// quit function
void quit()
{
    // destroy the renderer and the window
    SDL_DestroyRenderer( renderer.renderer );
    SDL_DestroyWindow( renderer.window );

    // quit both SDL_Mix and SDL2
    Mix_Quit();
    SDL_Quit();

    exit(0);
}


int main()
{
    // execute Wally code
    /* remember to call these
     input.updateInput();

     SDL_Delay(10);

     renderer.draw();
     */

    quit();

    return 0;
}

