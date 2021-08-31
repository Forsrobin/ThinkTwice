#ifndef C9F3179B_0BC6_40A1_B34F_BEC4522CD642
#define C9F3179B_0BC6_40A1_B34F_BEC4522CD642

#include "TextureManager.h"
#include <string>

class Map
{
public:
  Map() {}
  ~Map() {}

  void LoadMap(const char *path, int sizeY, int sizeX, int tileSize, int scaledSize);

  void draw() override
  {
    TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);
  }

private:
};

#endif /* C9F3179B_0BC6_40A1_B34F_BEC4522CD642 */
