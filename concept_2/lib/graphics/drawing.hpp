#include "includes.hpp"
#include "timer.hpp"
#include <iostream>

class Colour {
public:
    short r, g, b, a;
    Colour(short r, short g, short b, short a=255);
};

class Window {
public:
    Window(unsigned short w, unsigned short h, unsigned fps = 60);
    virtual ~Window();

    void start();
    void hide();
    SDL_Window *window_ptr();
    SDL_Surface *surface_ptr();
private:
    unsigned short width, height;
    unsigned frame_rate;
    SDL_Window *window;
    SDL_Surface *base_surface;
};
