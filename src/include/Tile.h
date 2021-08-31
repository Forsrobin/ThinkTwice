#ifndef AD832478_2125_454B_9D56_6A2907713C4B
#define AD832478_2125_454B_9D56_6A2907713C4B

#include <SDL2/SDL.h>

class Tile
{
public:
  SDL_Rect srcRect, destRect;

  Tile() {}
  ~Tile() {}

  Tile(int xposSrc, int yposSrc, int xposScreen, int yposScreen, int tSize)
  {
    srcRect.x = xposSrc;
    srcRect.y = yposSrc;
    srcRect.w = srcRect.h = tSize;

    destRect.x = xposScreen;
    destRect.y = yposScreen;
    destRect.w = destRect.h = tSize;
  }
};

#endif /* AD832478_2125_454B_9D56_6A2907713C4B */
