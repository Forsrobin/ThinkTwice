#include "Player.h"

Player::Player(const char* path, int x, int y) {
  tex = TextureManager::LoadTexture(path);

  // Load texture from tileset.png
  srcRect.x = 4*32;
  srcRect.y = 0;
  srcRect.w = srcRect.h = 32;

  destRect.x = 32*x;
  destRect.y = 32*y;
  destRect.w = destRect.h = 32;

}