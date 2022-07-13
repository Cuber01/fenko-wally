extern "C"
{
    #include "wally/std/native_utils.h"
    #include "wally/data_structs/value.h"
    #include "wally/misc/common.h"
    #include "wally/data_structs/object.h"
}

#include "main.hpp"

// region Renderer

NATIVE_FUNCTION(draw)
{
    CHECK_ARG_COUNT("renderer.draw", 0);
    renderer.draw();

    return NULL_VAL;
}

// endregion

// region Draw

NATIVE_FUNCTION(pset)
{
    CHECK_ARG_COUNT("draw.pset", 3);
    draw.pset(AS_NUMBER(args[0]), AS_NUMBER(args[1]), AS_NUMBER(args[2]));

    return NULL_VAL;
}

NATIVE_FUNCTION(pget)
{
    CHECK_ARG_COUNT("draw.pget", 2);
    return NUMBER_VAL(draw.pget(args[0], args[1]));
}

NATIVE_FUNCTION(rect)
{
    CHECK_ARG_COUNT("draw.rect", 5);
    draw.rect(AS_NUMBER(args[0]),
              AS_NUMBER(args[1]),
              AS_NUMBER(args[2]),
              AS_NUMBER(args[3]),
              AS_NUMBER(args[4]));

    return NULL_VAL;
}

NATIVE_FUNCTION(rectfill)
{
    CHECK_ARG_COUNT("draw.rectfill", 5);
    draw.rectfill(AS_NUMBER(args[0]),
                  AS_NUMBER(args[1]),
                  AS_NUMBER(args[2]),
                  AS_NUMBER(args[3]),
                  AS_NUMBER(args[4]));

    return NULL_VAL;
}

NATIVE_FUNCTION(circ)
{
    CHECK_ARG_COUNT("draw.circ", 4);
    draw.circ(AS_NUMBER(args[0]),
              AS_NUMBER(args[1]),
              AS_NUMBER(args[2]),
              AS_NUMBER(args[3]));

    return NULL_VAL;
}

NATIVE_FUNCTION(circfill)
{
    CHECK_ARG_COUNT("draw.circfill", 4);
    draw.circfill(AS_NUMBER(args[0]),
                  AS_NUMBER(args[1]),
                  AS_NUMBER(args[2]),
                  AS_NUMBER(args[3]));

    return NULL_VAL;
}

NATIVE_FUNCTION(clear)
{
    CHECK_ARG_COUNT("draw.clear", 1);
    draw.clear(AS_NUMBER(args[0]));

    return NULL_VAL;
}

// endregion

// region Input

NATIVE_FUNCTION(update)
{
    CHECK_ARG_COUNT("input.update", 0);
    input.updateInput();
}

NATIVE_FUNCTION(isButtonPressed)
{
    CHECK_ARG_COUNT("input.isButtonPressed", 1);
    return BOOL_VAL(input.isButtonPressed(AS_NUMBER( (int)args[0]) ));
}

NATIVE_FUNCTION(isMouseButtonPressed)
{
    CHECK_ARG_COUNT("input.isMouseButtonPressed", 1);
    return BOOL_VAL(input.isMouseButtonPressed(AS_NUMBER( (int)args[0]) ));
}

// endregion

// region Sound

// TODO this code is terrible performance-wise and likely to create a memory leak (we don't free sounds and music)
NATIVE_FUNCTION(playSound)
{
    CHECK_ARG_COUNT("sound.playSound", 1);
    Mix_Chunk* chunk = sound.loadSound(AS_CSTRING(args[0]));
    sound.playSound(chunk);

    return NULL_VAL;
}

NATIVE_FUNCTION(playMusic)
{
    CHECK_ARG_COUNT("sound.playMusic", 1);
    Mix_Music* music = sound.loadMusic(AS_CSTRING(args[0]));
    sound.playMusic(music);

    return NULL_VAL;
}

NATIVE_FUNCTION(loopMusic)
{
    CHECK_ARG_COUNT("sound.loopMusic", 1);
    Mix_Music* music = sound.loadMusic(AS_CSTRING(args[0]));
    sound.loopMusic(music);

    return NULL_VAL;
}

NATIVE_FUNCTION(pauseMusic)
{
    CHECK_ARG_COUNT("sound.pauseMusic", 0);
    sound.pauseMusic();

    return NULL_VAL;
}

NATIVE_FUNCTION(resumeMusic)
{
    CHECK_ARG_COUNT("sound.resumeMusic", 0);
    sound.resumeMusic();

    return NULL_VAL;
}

NATIVE_FUNCTION(haltMusic)
{
    CHECK_ARG_COUNT("sound.haltMusic", 0);
    sound.haltMusic();

    return NULL_VAL;
}

// endregion


void defineFenko(Table* table)
{
    ObjClass* WRenderer = newClass(copyString("renderer", 8));
    ObjClass* WDraw     = newClass(copyString("draw",     4));
    ObjClass* WInput    = newClass(copyString("input",    5));
    ObjClass* WSound    = newClass(copyString("sound",    5));

    #define DEFINE_RENDERER_METHOD(name, method) defineNativeFunction(WRenderer->methods, name, method)
    #define DEFINE_DRAW_METHOD(name, method) defineNativeFunction(WDraw->methods, name, method)
    #define DEFINE_INPUT_METHOD(name, method) defineNativeFunction(WInput->methods, name, method)
    #define DEFINE_SOUND_METHOD(name, method) defineNativeFunction(WSound->methods, name, method)

    DEFINE_SOUND_METHOD("haltMusic",   haltMusicNative);
    DEFINE_SOUND_METHOD("resumeMusic", resumeMusicNative);
    DEFINE_SOUND_METHOD("pauseMusic",  pauseMusicNative);
    DEFINE_SOUND_METHOD("loopMusic",   loopMusicNative);
    DEFINE_SOUND_METHOD("playMusic",   playMusicNative);
    DEFINE_SOUND_METHOD("playSound",   playSoundNative);

    DEFINE_INPUT_METHOD("isMouseButtonPressed", isMouseButtonPressedNative);
    DEFINE_INPUT_METHOD("isButtonPressed",      isButtonPressedNative);
    DEFINE_INPUT_METHOD("update",               updateNative);

    DEFINE_DRAW_METHOD("clear",        clearNative);
    DEFINE_DRAW_METHOD("circfill",     circfillNative);
    DEFINE_DRAW_METHOD("circ",         circNative);
    DEFINE_DRAW_METHOD("rectfill",     rectfillNative);
    DEFINE_DRAW_METHOD("rect",         rectNative);
    DEFINE_DRAW_METHOD("pget",         pgetNative);
    DEFINE_DRAW_METHOD("pset",         psetNative);

    DEFINE_SOUND_METHOD("draw",        drawNative);

    #undef DEFINE_RENDERER_METHOD
    #undef DEFINE_DRAW_METHOD
    #undef DEFINE_INPUT_METHOD
    #undef DEFINE_SOUND_METHOD

    tableDefineEntry(
            table,
            WRenderer->name,
            OBJ_VAL(newInstance(WRenderer))
    );

    tableDefineEntry(
            table,
            WDraw->name,
            OBJ_VAL(newInstance(WDraw))
    );

    tableDefineEntry(
            table,
            WInput->name,
            OBJ_VAL(newInstance(WInput))
    );

    tableDefineEntry(
            table,
            WSound->name,
            OBJ_VAL(newInstance(WSound))
    );

}