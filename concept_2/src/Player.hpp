#include <graphics/graphics.hpp>
using namespace Graphics;

class Player {
private:
    float width, height;
    std::string name;
    bool isfalling = true;

public:
    Point origin;
    std::vector<float> dir = {0, 0};
    float mass = this->width * this->height;

    Player(std::string, const Point &, float, float);
    Player &render(SDL_Renderer *);
    void gravity(float);
    void move();
    void collide(Player *);
};
