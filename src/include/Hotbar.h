#ifndef AC0662A5_54DF_478E_BC8C_E91A08BC0AC6
#define AC0662A5_54DF_478E_BC8C_E91A08BC0AC6

#include "TextureManager.h"
#include "Game.h"
#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include <string>

class Hotbar
{
public:
  SDL_Rect srcRect, destRect;
  SDL_Texture *tex;

  std::map<std::string, SDL_Texture *> hotbarMap;

  Hotbar()
  {
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = srcRect.h = 32;

    destRect.x = 32;
    destRect.y = 32;
    destRect.w = destRect.h = 32;
  }

  void LoadTexture(const char *path)
  {
    tex = TextureManager::LoadTexture(path);
  }

  ~Hotbar() {}

  void draw()
  {
    TextureManager::Draw(tex, srcRect, destRect, SDL_FLIP_NONE);
  }
};

#endif /* AC0662A5_54DF_478E_BC8C_E91A08BC0AC6 */
