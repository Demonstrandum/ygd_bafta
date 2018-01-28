#include "core.hpp"
#include "timer.hpp"
#include <iostream>

const long double PI = 3.141592653589793238462643383279502884;
const long double TAU = PI * 2L;

namespace Graphics {
    class Colour {
    public:
        short r, g, b, a;
        Colour(short r, short g, short b, short a=255);
    };

    extern Colour filler;
    extern Colour stroker;

    Colour   fill(Colour);
    Colour stroke(Colour);

    namespace Mode { enum { NEITHER, FILL, STROKE }; }

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
}
