#include "includes.hpp"

class Window {
public:
    Window(unsigned short w, unsigned short h, unsigned fps = 60);
    ~Window();

    void show();
    void hide();
    SDL_Window *window_ptr();
    SDL_Surface *surface_ptr();
private:
    unsigned short width, height;
    unsigned frame_rate;
    SDL_Window *window;
    SDL_Surface *base_surface;
};
