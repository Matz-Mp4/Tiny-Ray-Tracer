#pragma once

#include <SDL2/SDL.h>
#include "color.h"

class Window{
public:
    unsigned int width;
    unsigned int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    Window(unsigned int width, unsigned int height);
    ~Window();

    void init();
    void set_pixel(unsigned int x, unsigned int y, int r, int g, int b);
    bool should_close();
    void close();
};
