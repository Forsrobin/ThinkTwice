#include "Map.h"
#include "sstream"
#include <iostream>
#include <fstream>
#include <string>

void Map::LoadMap(const char *mapFile)
{
  std::ifstream input(mapFile);
  for (std::string line; getline(input, line);)
  {
    std::cout << line << std::endl;
  }
}