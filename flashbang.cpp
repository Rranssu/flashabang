#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <ostream>
#include <ostream>

using std::cin;
using std::cout;
using std::string;
using std::cerr;

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("Window cant be cooked right now cuh: %s", SDL_GetError());
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("flashbang", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 225, 225, 225, 225);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, 2, 2048) == -1)
    {
        SDL_Log("Error initializing SDL_mixer: %s", Mix_GetError());
    }
    Mix_Chunk* audio = Mix_LoadWAV("audio/audio.wav");
    Mix_PlayChannel(-1, audio, 0);
    SDL_Delay(50000000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}