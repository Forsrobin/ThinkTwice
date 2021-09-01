#ifndef A0426B6D_E1AA_4260_9B47_A3C7F76F839D
#define A0426B6D_E1AA_4260_9B47_A3C7F76F839D


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <vector>


class Game
{
public:

  Game();
  ~Game();

  void init(const char *title, int xpos, int ypos, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();
  bool running() { return isRunning; };

  static SDL_Renderer *renderer;
  static SDL_Event event;
  static bool isRunning;

private:
  SDL_Window *window;
};

#endif /* A0426B6D_E1AA_4260_9B47_A3C7F76F839D */
