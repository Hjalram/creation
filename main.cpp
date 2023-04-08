#include <iostream>
#include <SDL2/SDL.h>

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

int window_x;
int window_y;
int window_w;
int window_h;

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);

  window_x = SDL_WINDOWPOS_UNDEFINED;
  window_y = SDL_WINDOWPOS_UNDEFINED;
  window_w = 800;
  window_h = 600;

  window = SDL_CreateWindow("title", window_x, window_y, window_w, window_h, SDL_WINDOW_ALLOW_HIGHDPI);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_Event event;
  while(true) {
    if(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) {
        break;
      }
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
