#ifndef C9F3179B_0BC6_40A1_B34F_BEC4522CD642
#define C9F3179B_0BC6_40A1_B34F_BEC4522CD642

#include "TextureManager.h"
#include <string>

class Map
{
public:
  Map() {}
  ~Map() {}

  void AddTile(std::string textureID);
  void LoadMap(const char *mapFile);

  // Read level1.txt
  // Load all textures into a vector
  // Display those textures in the render function

private:
};

#endif /* C9F3179B_0BC6_40A1_B34F_BEC4522CD642 */
