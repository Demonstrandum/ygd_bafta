#include "shapes.hpp"

class Game : public Window {
public:
    Game(unsigned short, unsigned short, unsigned fps = 60);
    ~Game();
    void start();
    virtual void setup();
    virtual void draw();

    void background(Colour);

    template<class Graphic>  // Must define here, can't define in seperate file
    void render(Graphic *item) { item->render(this->renderer); }
private:
    unsigned short width, height;
    unsigned frame_rate;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *base_surface;
};
