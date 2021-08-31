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

  int srcX = 0;
  int srcY = 0;

  for (int y = 0; y < sizeY; y++)
  {
    for (int x = 0; x < sizeX; x++)
    {
      mapFile.get(c);
      srcY = (atoi(&c) * 32);
      mapFile.get(c);
      srcX = (atoi(&c) * 32);

      //Add tile to vector
      Tile tile(srcX, srcY, x * 32, y * 32, 32);
      this->mapTiles.push_back(tile);

      mapFile.ignore();
    }
  }

  mapFile.close();
}

void Map::AddTile(int xpos, int ypos)
{
  int x = (xpos / tileSize) * tileSize;
  int y = (ypos / tileSize) * tileSize;

  if (!TileExsists(x, y))
  {
    Tile tile(64, 0, x, y, tileSize);
    this->placedTiles.push_back(tile);
  }
}

bool Map::TileExsists(int xpos, int ypos)
{
  bool foundTile = false;

  for (auto tile : placedTiles)
    if (tile.destRect.x == xpos && tile.destRect.y == ypos)
      foundTile = true;

  for (auto tile : mapTiles)
    if (tile.destRect.x == xpos && tile.destRect.y == ypos && tile.srcRect.x == 0 && tile.srcRect.y == 0)
      foundTile = true;

  return foundTile;
}