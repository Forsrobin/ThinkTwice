#ifndef C9F3179B_0BC6_40A1_B34F_BEC4522CD642
#define C9F3179B_0BC6_40A1_B34F_BEC4522CD642

#include "Tile.h"
#include "TextureManager.h"
#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Map
{
public:
  std::vector<Tile> mapTiles;
  std::vector<Tile> placedTiles;
  std::string mapTag;

  SDL_Texture *tex;

  int tileSize = 32;

  Map() {}
  Map(std::string mt, int ts)
  {
    mapTag = mt;
    tileSize = ts;
  }
  ~Map() {}

  void LoadMap(const char *path, int sizeY, int sizeX);
  void AddTile(int xpos, int ypos);
  bool TileExsists(int xpos, int ypos);

  void draw()
  {
    for (auto tile : mapTiles)
      TextureManager::Draw(tex, tile.srcRect, tile.destRect, SDL_FLIP_NONE);

    for (auto tile : placedTiles)
      TextureManager::Draw(tex, tile.srcRect, tile.destRect, SDL_FLIP_NONE);
  }

private:
};

#endif /* C9F3179B_0BC6_40A1_B34F_BEC4522CD642 */
