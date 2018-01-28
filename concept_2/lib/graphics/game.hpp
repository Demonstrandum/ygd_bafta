#include "shapes.hpp"

namespace Graphics {
    class Game : public Window {
    public:
        Game(unsigned short, unsigned short, unsigned fps = 60);
        virtual ~Game();
        void start();
        virtual void setup();
        virtual void draw();

        void background(Colour);

        template<class Graphic>  // Must define here, can't define in seperate file
        Graphic &render(Graphic *item) { return item->render(this->renderer); }
    private:
        unsigned short width, height;
        unsigned frame_rate;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Surface *base_surface;
    };
}
