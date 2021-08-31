#include "Map.h"
#include "Vector2D.h"
#include "sstream"
#include <iostream>
#include <fstream>
#include <string>

void Map::LoadMap(const char *path, int sizeY, int sizeX, int tileSize, int scaledSize)
{

  char c;
  std::fstream mapFile;
  mapFile.open(path);

  int srcX, srcY;

  for (int y = 0; y < sizeY; y++)
  {
    for (int x = 0; x < sizeX; x++)
    {
      mapFile.get(c);
      srcY = atoi(&c) * tileSize;
      mapFile.get(c);
      srcX = atoi(&c) * tileSize;

      SDL_Rect srcRect, destRect;
      Vector2D position;

      position.x = srcX;
      position.y = srcY;
      srcRect.x = srcX;
      srcRect.y = srcY;
      srcRect.w = srcRect.h = tileSize;

      destRect.x = srcX;
      destRect.y = srcY;
      destRect.w = destRect.h = tileSize * scaledSize;

      SDL_Surface *tempSurface = IMG_Load("assets/img/tileset.png");
      SDL_Texture *tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
      SDL_FreeSurface(tempSurface);

      SDL_RenderCopyEx(Game::renderer, tex, &srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
      
      mapFile.ignore();
    }
  }
  mapFile.close();
}
