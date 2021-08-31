#include "Game.h"
#include "Vector2D.h"
#include "Map.h"

SDL_Renderer *Game::renderer = nullptr;
SDL_Event Game::event;

Map* map;

bool Game::isRunning = false;

Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, bool fullscreen)
{
  std::cout << "Test" << std::endl;
  int flags = 0;
  if (fullscreen)
    flags = SDL_INIT_EVERYTHING;

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    window = SDL_CreateWindow(title, xpos, ypos, 800, 800, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer)
      SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    isRunning = true;
  }

  // Init font library
  if (TTF_Init() == -1)
    std::cout << "Error opening TTF Fonts" << std::endl;

  // Init entities
  map = new Map("terrain", 32);
  map->LoadMap("assets/maps/level1.txt", 25, 25);

}

void Game::handleEvents()
{
  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;
  case SDL_MOUSEBUTTONDOWN:
    //Add tile to map
    int x, y;
    SDL_GetMouseState(&x, &y);
    map->AddTile(x, y);
    break;
  default:
    break;
  }
}

void Game::update()
{

}

void Game::render()
{
  SDL_RenderClear(renderer);

  // Draw our stuff
  map->draw();

  SDL_RenderPresent(renderer);
}
void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}