#include <graphics/graphics.hpp>
#include "Sprite.hpp"

using namespace Graphics;

class Player : public Sprite {
public:
    Point origin;
    float width, height;

    std::vector<float> dir = {0, 0};
    float mass = this->width * this->height;

    std::string name;

    Player() : Sprite() {}
    Player(std::string, const Point &, float, float);
    Player &render(SDL_Renderer *);

    void gravity(float);
    void move(Side *);
    void reverse();

    template<class Entity>
    Side *collide(Entity *other)
    { return collision(this, other); }
};
