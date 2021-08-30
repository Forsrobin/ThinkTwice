#ifndef FE22E229_525A_4BAB_B13B_6934DE682A8A
#define FE22E229_525A_4BAB_B13B_6934DE682A8A

#include "Game.h"
#include <map>
#include <string>
#include <SDL2/SDL.h>

class TextureManager
{
public:
  TextureManager() {}
  ~TextureManager() {}

  SDL_Texture *LoadTexture(const char *path)
  {
    SDL_Surface *tempSurface = IMG_Load(path);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
  }

};

#endif /* FE22E229_525A_4BAB_B13B_6934DE682A8A */
