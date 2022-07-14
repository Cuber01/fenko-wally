#include <SDL_mixer.h>
#include "sound/sound.hpp"

CSound::CSound()
{
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(1);
    }
}

Mix_Music* CSound::loadMusic(const char* musicPath)
{
    Mix_Music* rv = Mix_LoadMUS( musicPath );
    if( rv == nullptr )
    {
        printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(1);
    }

    return rv;
}

Mix_Chunk* CSound::loadSound(const char* soundPath)
{
    Mix_Chunk* rv = Mix_LoadWAV( soundPath );
    if( rv == nullptr )
    {
        printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(1);
    }

    return rv;
}

void CSound::playSound(Mix_Chunk* sound, uint8_t loops)
{
    Mix_PlayChannel(-1, sound, loops);
}

void CSound::playMusic(Mix_Music* musicTrack, uint8_t loops)
{
    Mix_PlayMusic( musicTrack, loops );
}

void CSound::freeSound(Mix_Chunk* sound)
{
    Mix_FreeChunk(sound);
}

void CSound::freeMusic(Mix_Music* musicTrack)
{
    Mix_FreeMusic(musicTrack);
}


void CSound::loopMusic(Mix_Music* musicTrack)
{
    Mix_PlayMusic( musicTrack, -1 );
}

void CSound::pauseMusic()
{
    Mix_PauseMusic();
}

void CSound::resumeMusic()
{
    Mix_ResumeMusic();
}

void CSound::haltMusic()
{
    Mix_HaltMusic();
}






