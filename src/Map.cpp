#include "Map.h"
#include "sstream"
#include <iostream>
#include <fstream>

void Map::LoadMap(const char *path, int sizeY, int sizeX)
{

  char c;
  std::fstream mapFile;
  mapFile.open(path);

  tex = TextureManager::LoadTexture("assets/img/tileset.png");

  int srcX, srcY;

  for (int y = 0; y < sizeY; y++)
  {
    for (int x = 0; x < sizeX; x++)
    {
      mapFile.get(c);
      srcY = atoi(&c) * tileSize;
      mapFile.get(c);
      srcX = atoi(&c) * tileSize;

      //Add tile to vector
      Tile tile(srcX, srcY, x * tileSize, y * tileSize, tileSize);
      this->tiles.push_back(tile);

      mapFile.ignore();
    }
  }

  mapFile.close();
}
