#ifndef FENKO_MAIN_HPP
#define FENKO_MAIN_HPP

#include "graphics/render.hpp"
#include "input/input_api.hpp"
#include "graphics/drawing_api.hpp"
#include "sound/sound.hpp"
#include "graphics/sprite.hpp"

extern bool running;

extern CRenderHandler renderer;
extern CInput         input;
extern CDraw          draw;
extern CSound         sound;
extern CSprite        sprite;

#endif //FENKO_MAIN_HPP
