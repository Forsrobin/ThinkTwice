#ifndef B0901615_6C03_4E80_A930_A29D54B2292B
#define B0901615_6C03_4E80_A930_A29D54B2292B

#include <SDL2/SDL.h>
#include "TextureManager.h"

class Player
{
public:

  SDL_Texture* tex;
  SDL_Rect srcRect, destRect;
  int xpos;
  int ypos;

  Player() {}
  ~Player() {}

  Player(const char* path, int x, int y);

  void move(int x, int y) {
    destRect.x += 32*x;
    destRect.y += 32*y;
  }

  void draw() {
    TextureManager::Draw(tex, srcRect, destRect, SDL_FLIP_NONE);
  }

};

#endif /* B0901615_6C03_4E80_A930_A29D54B2292B */
