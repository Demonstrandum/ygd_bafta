#include "shapes.hpp"

namespace Graphics {
    class Game : public Window {
    public:
        Game(unsigned short, unsigned short, unsigned fps = 60);
        virtual ~Game();
        void start();
        virtual void setup();
        virtual void draw();
        virtual void on_resize(SDL_Event event);
        virtual void key_pressed();
        virtual void key_released();

        void background(Colour);

        template<class Graphic>  // Must define here, can't define in seperate file
        Graphic &render(Graphic *item) { return item->render(this->renderer); }
    private:
        char *title = "";
        unsigned short width, height;
        unsigned frame_rate;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Surface *base_surface;
        SDL_Event event;
        SDL_Keycode key_down;
        SDL_Keycode key_up;
    };
}
